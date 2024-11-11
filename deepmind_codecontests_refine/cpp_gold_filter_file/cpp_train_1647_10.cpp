#include<bits/stdc++.h>
using namespace std;

bool vis[10];

int main()
{
  int x;
  for(int i=0;i<4;i++)
    cin>>x,vis[x]=true;
  
  if(vis[1] && vis[4] && vis[7] && vis[9])
    cout<<"YES\n";
  else
    cout<<"NO\n";
}
