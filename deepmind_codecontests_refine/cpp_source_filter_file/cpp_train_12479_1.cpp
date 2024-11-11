#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define opinit() rep(i,9){if(i<3)op[i]='+';else if(i<6)op[i]='-';else op[i]='*';}
#define a n[0]
#define b n[1]
#define c n[2]
#define d n[3]
#define op1 op[0]
#define op2 op[1]
#define op3 op[2]

int ans(int x,int y,char op){
	switch(op){
	case '+':
		return x+y;
	case '-':
		return x-y;
	case '*':
		return x*y;
	}
	
}

int main(){
	vector<int>n(4);
	vector<char>op(9);
	opinit();
	
	int A,B;
	
	while(cin >> a >> b >> c >> d && a || b || c || d){
		sort(n.begin(),n.end());
		bool flag = false;
		do{
			//sort(op.begin(),op	.end());
			do{
				/*1p^[*/
				A = ans(a,b,op1);
				B = ans(A,c,op2);
				if( ans(B,d,op3) == 10){
					printf("((%d %c %d) %c %d) %c %d\n",a,op1,b,op2,c,op3,d);
					flag = true;
					goto end;
				}
				/*2p^[*/
				A = ans(b,c,op2);
				B = ans(a,A,op1);
				if( ans(B,d,op3) == 10){
					printf("(%d %c (%d %c %d)) %c %d\n",a,op1,b,op2,c,op3,d);
					flag = true;
					goto end;
				}
				/*3p^[*/
				A = ans(c,d,op3);
				B = ans(b,A,op2);
				if( ans(a,B,op1) == 10){
					printf("%d %c (%d %c (%d %c %d))\n",a,op1,b,op2,c,op3,d);
					flag = true;
					goto end;
				}
				/*4p^[*/
				A = ans(a,b,op1);
				B = ans(c,d,op3);
				if( ans(A,B,op2) == 10){
					printf("(%d %c %d) %c (%d %c %d)\n",a,op1,b,op2,c,op3,d);
					flag = true;
					goto end;
				}
				/*5p^[*/
				A = ans(b,c,op2);
				B = ans(A,d,op3);
				if( ans(a,B,op1) == 10){
					printf("%d %c ((%d %c %d) %c %d)\n",a,op1,b,op2,c,op3,d);
					flag = true;
					goto end;
				}
			}while(next_permutation(op.begin(),op.end()));
		}while(next_permutation(n.begin(),n.end()));
		end:
		if(!flag)cout << "0" << endl;
	}
}
	