#include <bits/stdc++.h>
using namespace std;
int main(){
int n,r=0,b=0;
string a;
cin>>n>>a;
for(int i=0;i<n;i++){
	if(a[i]=="R")
	r++;
	else
	b++;
}
if(r>b)
cout<<"Yes";
else
cout<<"No";
}
