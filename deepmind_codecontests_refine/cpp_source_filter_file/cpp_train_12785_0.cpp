#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,a,b,c[100000];
  long long ans=0
    cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    ans+=a;
    c[i]=a+b;
  }
  sort(c,c+n,greater<int>());
  for(int i=1; i<n; i+=2) {
    ans-=c[i];
  }
  cout << ans << endl;
}