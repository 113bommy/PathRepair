//?????????
//??????00-440415D???Smart_Calculator.cpp

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <stdio.h>

using namespace std;

string S = "1+2*(3+4)";
size_t cur = 0;

int expression();

int digit(){
	assert(isdigit(S[cur]));
	int n = S[cur++]-'0';
	return n;
}

int number(){
	int n = digit();
	while(cur<S.size() && isdigit(S[cur])){
		n = n*10 + digit();
	}
	return n;
}

int factor(){
	if(S[cur] != '('){
		return number();
	}else{
		cur++;
		int n = expression();
		assert(S[cur])==')');
		cur++;
		return n;
	}
}

//??????????????????????????????
int term(){
	int a = factor();
	while(cur < S.size() && (S[cur] == '*' || S[cur] == '/')){
		char op = S[cur++];
		int b = factor();
		if(op == '*'){
			a *= b;
		}else if(op == '/'){
			a /= b;
		}
	}
	return a;
}

int expression(){
	int sum = term();
	while(S[cur] == '+' || S[cur] == '-'){
		char op = S[cur++];
		int b = term();
		if(op == '+'){
			sum += b;
		}else if(op == '-'){
			sum -= b;
		}
	}
	return sum;
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cur = 0;
		cin >> S;
		S.resize(S.size-1);
		cout << expression() << endl;
	}
	return 0;
}