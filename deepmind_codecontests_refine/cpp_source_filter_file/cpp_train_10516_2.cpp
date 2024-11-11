#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int S[1000], top;

void push(int x){
	S[top++] = x;
}

void pop(){
	top--;
	return S[top + 1];
}

int main(){
	int a, b;
	char s[200];
	top = 0;
	while (scanf("%s", s) != EOF){
		if (s[0] == '+'){
			a = pop();
			b = pop();
			push(a + b);
		}else if(s[0] == '-'){
			b = pop();
			a = pop();
			push(a - b);
		}else if (s[0] == '*'){
			b = pop();
			a = pop();
			push(a * b);
		}
		else{
			push(atoi(s));
		}
	}
	printf("%d\n", pop());
	return 0;
}