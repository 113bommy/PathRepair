#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin>>s;
int len=s.size();
int a[300] = {0};
for(int i=0;i<len;i++)
{
a[s[i]]=1;
}
if(a['N']!=a['S'])
puts("No");
else if(a['W']!=a['E'])
puts("No");
else 
puts("Yes");
return 0;
}