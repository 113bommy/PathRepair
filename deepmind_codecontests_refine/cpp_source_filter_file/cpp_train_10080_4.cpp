#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<string> v;
string buf[5002];

int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		for(int j=i;j<s.size() && j<i+6;j++) {
			v.push_back(s.substr(i,j-i+1))
		}
	sort(v.begin(),v.end());
	int k;
	cin>>k;
	k--;
	v.erase(unique(v.begin(),v.end()),v.end());
	cout<<v[k];
	return 0;
}