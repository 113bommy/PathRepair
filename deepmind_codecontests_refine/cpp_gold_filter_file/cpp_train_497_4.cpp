#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n>>s;
  	n=0;
  	for(auto a:s)n+=a=='R'?1:-1;
  	cout<<(n>0?"Yes":"No")<<endl;
  	return 0;
}
