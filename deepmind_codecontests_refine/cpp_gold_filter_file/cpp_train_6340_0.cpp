#include<iostream>
#include<stdio.h>
#include<cmath>
#define INF 9999999
using namespace std;
int a,b,c;
int main(){
	while(cin>>a>>b){
		while(b!=0){
			c=a%b;
			a=b;
			b=c;
		}
		cout<<a<<endl;
	}
	return 0;
}