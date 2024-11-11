#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string t;
	cin>>t;
	for(int i=0;i<t.size();i++)if(t[i]=='?')t[i]='D';
	cout<<t;
	return 0;
}
