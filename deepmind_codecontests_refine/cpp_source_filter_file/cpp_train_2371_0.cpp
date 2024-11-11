#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>l(n);
	for(int i=0;i<n;i++)
		cin>>vl[i];
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++){
				int a=vl[i],b=vl[j],c=vl[k];
				if(a==b||a==c||b==c)
					continue;
				if(a+b>c&&a+c>b&&b+c>a)
					cnt++;
			}
	cout<<cnt<<endl;
	return 0;
}