#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<(int)N;i++)
int main()
{
  int N,a,b,first=1;
  cin>>N;
  vector<int> A(N,0),Edge(N-1,0),Color(N,0);
  rep(i,N-1)
  {
    cin>>a>>Edge.at(i);
    Edge.at(i)--,A.at(Edge.at(i))=a-1;
  }
  rep(i,N-1)
  {
    a=A.at(i+1),b=Color.at(a)+1;
    Color.at(a)=A.at(i+1)=(b==A.at(a)?b+1:b);
    first=max(b,first);
  }
  cout<<first<<endl;
  for(b:Edge)cout<<A.at(b)<<endl;
}