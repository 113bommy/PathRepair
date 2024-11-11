#include <bits/stdc++.h>
using namespace std;
 
int main()
{
int n,l,i;
cin>>n>>l;
vector<string > v(n);
for(i=0;i<n;i++)
cin>>v[i];
sort(v.begin(),v.end());
string s="";
for(i=0;i<n;i++)
s+=v[i];
cout<<s<<endl;
 
return 0;
}