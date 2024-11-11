#include <bits/stdc++.h>
using namespace std;
long long cnt[100010];
int main() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }
  long long tot = 0;
  for (int i = 100000; i >= 1; i--) {
    tot += cnt[i];
    if (tot % 2 != 0) {
      cout << "Conan";
      return 0;
    }
  }
  cout << "Agasa";
}
