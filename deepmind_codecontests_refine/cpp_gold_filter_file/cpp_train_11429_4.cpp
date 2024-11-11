#include<bits/stdc++.h>
using namespace std;
int main()
{
string s,s1;
cin>>s>>s1;
s1.erase(s1.begin()+s1.length()-1);
if(s==s1)
cout<<"Yes";
else
cout<<"No";
}