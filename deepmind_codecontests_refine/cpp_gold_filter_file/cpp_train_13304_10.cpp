#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int L,R; cin>>L>>R;
  if(R-L>3000){
    cout<<0<<endl;
    return 0;
  }
  int best=3000;
  for(int i=L; i<=R; i++){
    for(int j=i+1; j<=R; j++){
      best=min(best,(i*j)%2019);
    }
  }
  cout<<best<<endl;
}
