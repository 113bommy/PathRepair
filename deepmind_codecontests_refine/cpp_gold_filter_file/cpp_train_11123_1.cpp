#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll H,W,h,w; cin>>H>>W>>h>>w;
  ll max=1000000000/(h*w);
  
  ll hu=(H/h)*(W/w);
    ll sei=H*W-hu;
  
  if(max*sei-(max*(h*w-1)+1)*hu<=0){cout<<"No"<<endl;
                    return 0;}
 cout<<"Yes"<<endl;
  rep(i, H){
    rep(j, W){
      if((i+1)%h==0 && (j+1)%w==0) cout<<(-max*(h*w-1)-1);
      else cout<<max;
      if(j==W-1)cout<<endl;
      else cout<<" ";
    }
  }
  
}
