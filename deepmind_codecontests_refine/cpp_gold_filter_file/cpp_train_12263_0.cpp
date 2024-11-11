#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d",&x);
	int now=ceil(x/1.08);
	if(floor(now*1.08)==x)cout<<ceil(x/1.08);
	else cout<<":(";
	return 0;
}