#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  long long n,a[100000],cnt=0,ans=0,b=1000000000;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]<0) {
      a[i]=abs(a[i]);
      cnt++;
    }
    b=min(b,a[i]);
    ans+=a[i];
  }
  if(cnt%2==1) {
    ans-=b*2;
  }
  cout << ans << endl;
}
