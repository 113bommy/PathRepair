#include <bits/stdc++.h>
using namespace std;
long long n, k, a;
long long rank_count[100];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ++rank_count[a];
  }
  int countn = 0;
  while (rank_count[k] < n) {
    ++countn;
    for (int i = k - 1; i >= 1; --i) {
      if (rank_count[i] != 0) {
        ++rank_count[i + 1];
        --rank_count[i];
      }
    }
  }
  cout << countn;
  return 0;
}
