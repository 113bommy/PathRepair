#include <iostream>

#include <cassert>
#include <cctype>
using namespace std;
string S;
size_t cur = 0;
int term();
int factor();
int expression();
int digit(){
	assert(isdigit(S[cur]));
	int n = S[cur] - '0'; 
	cur = cur + 1;
	return n;
}
int number(){
	int n = digit();
	while(cur<S.size() && isdigit(S[cur]))
		n = n*10 + digit();
	return n;
}
int expression(){
	int a =term();
	while (cur < S.size() && (S[cur] == '+' || S[cur] == '-')){
		char op = S[cur++];
		int b = term();
		if (op == '+') a += b;
		else a -= b;
	}
	return a;
}
int term(){
	int a =factor();
	while (cur < S.size() && (S[cur] == '*' || S[cur] == '/')){
		char op = S[cur++];
		int b = factor();
		if (op == '*') a *= b; else a /= b;
	}
	return a;
}
int factor(){
	if (S[cur] != '(') return number();
	cur += 1;
	int n = expression();
	assert(S[cur] == ')');
	cur +=1;
	return n;
}
int main() {

	int N;
	cin >> N;
	for (int i=0; i<N;++i){
		cur = 0;
		cin >> S;
		S.resize(S.size()-1);
		cout << expression() << endl;
	}
	return 0;

}