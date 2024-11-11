#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	unsigned int x,y;
	cin >>x>>y;
	printf("%d %d %.5f",x/y,x%y,(double)x/y);
	return 0;
}