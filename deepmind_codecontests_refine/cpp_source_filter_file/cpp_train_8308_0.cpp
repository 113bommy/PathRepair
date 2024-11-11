#include<bits/stdc++.h>
using namespace std;

int t[210000];
int main(){
	int n,a,l=1,c=1;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		t[a]=i;
	}
	for(int i=1;i<n;i++){
		if(t[i]<t[i+1])c++;
		else c=1;
		l=max(l,c);
	}
	cout<<n-z;
	return 0;
}
