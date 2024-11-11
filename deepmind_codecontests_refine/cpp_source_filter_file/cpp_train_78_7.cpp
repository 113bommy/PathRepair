#include<bits/stdc++.h>
using namespace std;
int N;
string S;
void dfs(int a,int b)
{
  if(a==N)
  {
    puts(S.c_str());
    return ;
  }
  for(int i=0;i<=b+1;i++)
  {
    S[a]='a'+i;
    dfs(a+1,max(b,i));
  }
  return ;
}
int main()
{
  cin>>N;
  dfs(0,-1);
  return 0;