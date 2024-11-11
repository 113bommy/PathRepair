#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

//FILE *in = freopen("input.txt", "r", stdin);
//FILE *out = freopen("output.txt", "w", stdout);

#define M 32768

typedef long long ll;

int mod(ll x) {
	return (M + x % M) % M;
}

class matrix{
public:
	int n, m;
	vector<vector<ll>> val;
	matrix() {
		n = m = 0;
	}
	matrix(int _n, int _m) {
		n = _n;
		m = _m;
		val = vector<vector<ll>>(_n, vector<ll>(_m, 0));
	}

	void addrow() {
		n++;
		val.push_back(vector<ll>(m));
	}

	void addcol() {
		m++;
		for(int i = 0; i < n; i++) {
			val[i].push_back(0);
		}
	}

	matrix operator + (const matrix obj) {
		if(n != obj.n || m != obj.m)
			throw exception(/*"n, m is not same!"*/);
		matrix res(n, m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) {
				res.val[i][j] = val[i][j] + obj.val[i][j];
			}
		}
		return res;
	}

	matrix operator - (const matrix obj) {
		if(n != obj.n || m != obj.m)
			throw exception(/*"n, m is not same!"*/);
		matrix res(n, m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) {
				res.val[i][j] = val[i][j] - obj.val[i][j];
			}
		}
		return res;
	}

	matrix operator * (const matrix obj) {
		if(n == 1 && m == 1) {
			matrix res(obj.n, obj.m);
			for(int i = 0; i < obj.n; i++) {
				for(int j = 0; j < obj.m; j++) {
					res.val[i][j] = obj.val[i][j] * val[0][0];
				}
			}
			return res;
		}

		if(obj.n == 1 && obj.m == 1) {
			matrix res(n, m);
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					res.val[i][j] = val[i][j] * obj.val[0][0];
				}
			}
			return res;
		}

		if(m != obj.n)
			throw exception(/*"m, obj.n is not same!"*/);
		matrix res(n, obj.m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < obj.m; j++) {
				long long sum = 0;
				for(int k = 0; k < m; k++) {
					sum += val[i][k] * obj.val[k][j];
				}
				res.val[i][j] = sum;
			}
		}
		return res;
	}

	matrix operator - () {
		matrix res(n, m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) {
				res.val[i][j] = -val[i][j];
			}
		}
		return res;
	}

	matrix trans() {
		matrix res(m, n);
		for(int i = 0; i < m; i ++) {
			for(int j = 0; j < n; j++) {
				res.val[i][j] = val[j][i];
			}
		}
		return res;
	}

	matrix get(matrix A, matrix B) {
		matrix res(A.m, B.m);
		for(int i = 0; i < A.m; i++) {
			for(int j = 0; j < B.m; j++) {
				res.val[i][j] = val[A.val[0][i]-1][B.val[0][j]-1];
			}
		}
		return res;
	}
};

int n;
map<char, matrix> vars;

matrix parsemat(char *& pos);
matrix parseone(char *& pos);
matrix parseexp(char *& pos);

matrix parsemat(char *& pos) {
	if(*pos != '[') throw exception(/*"Not a matrix!"*/);
	pos++;
	int cn = 0, cm = 0;
	matrix res;
	while(*pos != ']') {
		matrix item = parseexp(pos);
		if(res.n < cn + item.n) {
			for(int i = res.n; res.n < cn + item.n; i++)
				res.addrow();
		}
		if(res.m < cm + item.m) {
			for(int i = res.m; res.m < cm + item.m; i++)
				res.addcol();
		}
		for(int i = 0; i < item.n; i++) {
			for(int j = 0; j < item.m; j++) {
				res.val[cn+i][cm+j] = item.val[i][j];
			}
		}
		cm = cm + item.m;
		if(*pos == ';') {
			cm = 0;
			cn = res.n;
		}
		if(*pos == ']') {
			break;
		}
		pos++;
	}
	pos++;
	return res;
}

matrix parseone(char*& pos) {
	matrix res;

	while(*pos != '.') {
		switch(*pos) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			{
				res = matrix(1,1);
				long long val = 0;
				for(; '0' <= *pos && *pos <= '9'; ++pos) {
					val = val * 10 + (*pos - '0');
				}
				res.val[0][0] = val;
				return res;
			}
			break;
		case '-':
			{
				pos++;
				res = -parseone(pos);
				return res;
			}
			break;
		case '[':
			{
				return parsemat(pos);
			}
			break;
		case '(':
			{
				pos++;
				return parseexp(pos);
			}
			break;
		default:
			{
				if('A' <= *pos && *pos <= 'Z') {
					return vars[*pos++];
				}
			}
			break;
		}
	}
	return res;
}

matrix parsetrm(char *& pos) {
	matrix res = parseone(pos);
	while(*pos != '.') {
		switch(*pos) {
		case '*':
			{
				pos++;
				res = res * parsetrm(pos);
				break;
			}
		case '\'':
			{
				pos++;
				res = res.trans();
				break;
			}
		case '(':
			{
				pos++;
				matrix A = parseexp(pos);
				if(*pos != ',') throw exception(/*"something goes wrong!"*/);
				pos++;
				matrix B = parseexp(pos);
				if(*(pos-1) != ')') throw exception(/*"something goes wrong!"*/);
				res = res.get(A, B);
				break;
			}
		default:
			return res;
		}
	}
	return res;
}

matrix parseexp(char *& pos) {
	matrix res = parsetrm(pos);
	while(*pos != '.') {
		switch(*pos) {
		case '\'':
			{
				pos++;
				res = res.trans();
				break;
			}
		case '+':
			{
				pos++;
				res = res + parsetrm(pos);
				break;
			}
		case '-':
			{
				pos++;
				res = res - parsetrm(pos);
				break;
			}
		case ')':
			{
				++pos;
			}
		case ' ':
		case ']':
		case ';':
		case ',':
			{
				return res;
			}
		}
	}
	return res;
}

void output(matrix obj) {
	for(int i = 0; i < obj.n; i++) {
		printf("%d", mod(obj.val[i][0]));
		for(int j = 1; j < obj.m; j++) {
			printf(" %d", mod(obj.val[i][j]));
		}
		printf("\n");
	}
}

void init() {
	vars.clear();
}

void input() {
	init();

	for(int i = 0; i < n; i++) {
		char data[1000];
		gets(data);
		char *pos = data + 2;
		vars[data[0]] = parseexp(pos);
		output(vars[data[0]]);
	}
	printf("-----\n");
}

int main() {
	while(true){
		scanf("%d\n", &n);
		if(!n) break;
		input();
	}
	return 0;
}