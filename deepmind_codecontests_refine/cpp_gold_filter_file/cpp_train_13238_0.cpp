#include <bits/stdc++.h>
using namespace std;
const int MX = 110;
int freq[MX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int cnt = 0, sum = 0;
    for (int j = 1; j < MX; j++) {
      if (sum + freq[j] * j + x <= m) {
        sum += freq[j] * j;
        cnt += freq[j];
      } else {
        int k = max(0, m - x - sum) / j;
        assert(sum + k * j + x <= m);
        sum += k * j;
        cnt += k;
        break;
      }
    }
    cout << i - cnt << " ";
    freq[x]++;
  }
  cout << '\n';
  return 0;
}
