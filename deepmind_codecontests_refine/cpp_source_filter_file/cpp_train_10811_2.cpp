#include<bits/stdc++.h>
using namespace std;
int main()
{int n;cin>>n;string s;cin>>s;
int x=0,mx=0;
for(int i=0;i<n;i++)
{if(s[i]=='I')
{x++;
}
mx=max(x,mx);
}
if(s[i]=='D')
{x--;
}
cout<<mx;
return 0;
}