#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[1001],c=0,f=0,i;
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(a[i]=='C')
			c=1;
		if(c==1 and a[i]=='F')
			f=1;
	}
	if(f==1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
