#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t K,N;
  cin>>K>>N;
  vector<int64_t> a(2*N);
  for(int i=0;i<N;i++) {
    cin>>a[i];
    a[i+N]=a[i]+K;
  }
  int ans=K;
  for(int i=0;i<N;i++)
    ans=min(ans,a[i+N-1]-a[i]);
  cout<<ans<<endl;
}
    