#include <bits/stdc++.h> 

using namespace std;

int main(){
	int t,l;
	cin>>t>>l;
	string a[t];
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	sort(a,a+t);
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
}

