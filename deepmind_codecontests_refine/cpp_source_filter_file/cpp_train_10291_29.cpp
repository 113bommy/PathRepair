#include<iostream>

using namespace std;

int main(void)
{
  int x,y; cin>>x>>y;
  int g[]={1,3,1,2,1,2,1,1,2,1,2,1};
  
  cout<<(g[x-1]==g[y-1])?"Yes":"No"<<endl;
  return 0;
}