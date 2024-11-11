#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  long long n,ans=0,a;
  cin >> n;
  for(int i=1; i<=1000000; i++) {
    if(n%i==0) {
      a=n/i-1;
      if(a>i) {
        ans+=a;
      }
    }
  }
  cout << ans << endl;
}