#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main() {
  int N;
  cin >> N;
  vector <ll> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  if (N%2==1) {
    a.push_back(0);
  }
  sort(A.begin(),A.end());
  for (int i=0; i<N; i+=2) {
    if (A[i]!=A[i+1]) {
      cout << 0 << endl;
      return 0;
    }
  }
  int ans=1;
  for(int i=0; i<N/2; i++) {
    ans*=2;
    ans%=mod;
  }
  cout << ans << endl;
  return 0;
}

