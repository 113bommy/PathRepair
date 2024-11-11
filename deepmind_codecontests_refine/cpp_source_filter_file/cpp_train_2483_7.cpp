#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,M,x;
  cin>>N>>M;
  vector<int> a(N+1)
  for(int i=0;i<2*M;i++)
  {
    cin>>x;
    a.at(x)++;
  }
  for(int j=1;j<=N;j++)
  {
    cout<<a.at(j)<<endl;
  }
}