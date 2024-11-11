#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[5], hash[100];
  memset(hash, 0, sizeof(hash));
  int s = 0;
  for (int i = 0; i < 5; i++) {
    cin >> A[i];
    hash[A[i]]++;
    s += A[i];
  }
  int ans = s;
  for (int i = 100; i >= 1; i--) {
    if (hash[i] >= 2) {
      int aa = s;
      if (hash[i] >= 3)
        aa -= i * 3;
      else if (hash[i] == 2)
        aa -= i * 2;
      ans = min(ans, aa);
    }
  }
  cout << ans << endl;
  cout << flush;
  return 0;
}
