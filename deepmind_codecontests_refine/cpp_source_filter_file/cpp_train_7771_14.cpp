#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int freq[10001] = {0};
  int u, v, cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    freq[u]++;
    freq[v]++;
  }
  for (int i = 2; i <= 1000; i++) {
    if (freq[i] < 2 && freq[i] > 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
