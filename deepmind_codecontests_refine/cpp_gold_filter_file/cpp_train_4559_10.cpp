#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int A,B,M;
  cin>>A>>B>>M;
  vector<int> a(A), b(B);
  for(int i=0;i<A;i++)cin>>a[i];
  for(int j=0;j<B;j++)cin>>b[j];
  
  int ma=*min_element(a.begin(),a.end());
  int ans=1e9;
  for(int j=0;j<B;j++)ans=min(ans,ma+b[j]);

  for(int k=0;k<M;k++){
    int x,y,c;
    cin>>x>>y>>c;
    x-=1,y-=1;
    ans=min(ans,a[x]+b[y]-c);
  }

  cout<<ans<<endl;
}
