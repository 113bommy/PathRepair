#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/


const ll mod = 2;
struct Mod
{
	ll num;
	Mod() : num(0) { ; }
	Mod(ll n) : num(n % mod) { ; }
	operator ll() { return num; }
};


Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }

typedef Mod Data;

typedef vector<Data> Array;
typedef vector<Array> Matrix;

bool is_zero(Data dat) { return (abs(dat) < EPS); }

Matrix operator-(Matrix mat) {
	REP(i, mat.size()) REP(j, mat[0].size()) mat[i][j] = -mat[i][j];
	return mat;
}

Matrix operator+(Matrix lhs, const Matrix &rhs) {
	REP(i, lhs.size()) REP(j, lhs[0].size()) lhs[i][j] = lhs[i][j] + rhs[i][j];
	return lhs;
}

Matrix operator-(Matrix lhs, const Matrix &rhs) {
	REP(i, lhs.size()) REP(j, lhs[0].size()) lhs[i][j] = lhs[i][j] - rhs[i][j];
	return lhs;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
	Matrix res(lhs.size(), Array(rhs[0].size(), 0));
	REP(i, lhs.size()) REP(j, rhs[0].size()) REP(k, rhs.size())
		res[i][j] = lhs[i][k] * rhs[k][j] + res[i][j];
	return res;
}

Array operator+(const Array &lhs, const Array &rhs) {
	Array res = lhs;
	REP(i, rhs.size()) res[i] = res[i] + rhs[i];
	return res;
}

Array operator*(const Matrix &lhs, const Array &rhs) {
	Array res(lhs.size());
	REP(i, lhs.size())
		res[i] = inner_product(begin(lhs[i]), end(lhs[i]), begin(rhs), Data(0));
	return res;
}

Array operator*(Data scalar, const Array &rhs) {
	Array res(rhs.size());
	REP(i, rhs.size())
		res[i] = scalar * rhs[i];
	return res;
}

Matrix scalar(int size, Data k) {
	Matrix mat(size, Array(size, 0));
	REP(i, size) mat[i][i] = k;
	return mat;
}

Matrix operator^(const Matrix &lhs, const int n) {
	if (n == 0) return scalar(lhs.size(), 1);
	Matrix res = (lhs * lhs) ^ (n / 2);
	if (n % 2) res = res * lhs;
	return res;
}

int rankMat(Matrix A) {
	const int n = A.size(), m = A[0].size();
	int r = 0;
	for (int i = 0; r < n && i < m; ++i) {
		int pivot = r;
		for (int j = r + 1; j < n; ++j)
			if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
		swap(A[pivot], A[r]);
		if (is_zero(A[r][i])) continue;
		for (int k = m - 1; k >= i; --k)
			A[r][k] = A[r][k] / A[r][i];
		for (int j = r + 1; j < n; ++j)
			for (int k = m - 1; k >= i; --k)
				A[j][k] = (Data)-A[r][k] * A[j][i] + A[j][k];
		++r;
	}
	return r;
}

Array gauss_jordan(const Matrix& A, const Array& b)
{
	int n = A.size();
	Matrix B(n, Array(n + 1));
	REP(i, n)REP(j, n) B[i][j] = A[i][j];
	REP(i, n) B[i][n] = b[i];
	REP(i, n)
	{
		int pivot = i;
		FOR(j, i, n)
		{
			if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
		}
		swap(B[i], B[pivot]);

		if (abs(B[i][i]) < EPS) return Array();
		FOR(j, i + 1, n + 1) B[i][j] = B[i][j] / B[i][i];
		REP(j, n)
		{
			if (i != j)
			{
				FOR(k, i + 1, n + 1) B[j][k] -= B[j][i] * B[i][k];
			}
		}
	}
	Array x(n);
	REP(i, n) x[i] = B[i][n];
	return x;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n;
	cin >> n;
	Matrix A_(n, Array(n));
	REP(i, n)REP(j, n)
	{
		int a; cin >> a;
		A_[i][j] = Data(a);
	}
	Array b(n);
	REP(i, n)
	{
		int a; cin >> a;
		b[i] = Data(a);
	}
	int t; cin >> t;
	Matrix A = A_^t;
	Matrix Ab = A;
	REP(i, n) Ab[i].push_back(b[i]);
	int rA = rankMat(A), rAb = rankMat(Ab);
	if (rA != rAb)
	{
		cout << "none" << endl;
		return 0;
	}
	if (rA == rAb && rA != n)
	{
		cout << "ambiguous" << endl;
		return 0;
	}
	Array ans = gauss_jordan(A, b);
	REP(i, n) cout << ans[i] << (i == n - 1 ? "\n" : " ");
	return 0;
}