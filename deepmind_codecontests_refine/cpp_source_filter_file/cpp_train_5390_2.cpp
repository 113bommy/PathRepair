#include <bits/stdc++.h> 

using namespace std;

int main(){
	int t;
	string c;
	cin>>t>>c;
	vector<int> a(t,0);
	int r=0;
	for(int i=0;i<n;i++){
		if(c[i]=='R'){
			r++;
		}
		a[i]=r;
	}
	cout<<r-a[r-1];
}

