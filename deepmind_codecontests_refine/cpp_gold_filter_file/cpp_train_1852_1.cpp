#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int64_t i=0;i<(int64_t)N;i++)
int main()
{
  int64_t N,X,Y,count=0;
  cin>>N>>X>>Y;
  vector<int64_t> G(N,0);
  rep(i,N)rep(j,N)
  {
    count=1<<30;
    if(i<j){count=min(abs(j-i),min(abs(X-i-1)+1+abs(j+1-Y),abs(Y-i-1)+1+abs(j+1-X)));G.at(count-1)++;}
  }
  rep(i,N-1)cout<<G.at(i)<<endl;
}