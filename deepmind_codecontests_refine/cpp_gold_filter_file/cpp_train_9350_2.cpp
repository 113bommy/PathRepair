#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  long long n,k,x[100000],ans=1000000000;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> x[i];
  }
  for(int i=0; i<n-k+1; i++) {
    ans=min(ans,abs(x[i+k-1]-x[i])+min(abs(x[i]),abs(x[i+k-1])));
  }
  cout << ans << endl;
}