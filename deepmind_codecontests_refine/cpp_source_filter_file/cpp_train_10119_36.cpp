#include <bits/stdc++.h>
using namespace std;
int seq[100];
int ans;
vector<string> in;
void solve(int k, int l) {
  if (k <= l) {
    vector<int> buf(in.size());
    for (int i = 0; i < (int)in.size(); ++i) {
      buf[i] = 0;
    }
    for (int i = 0; i < (int)in.size(); ++i) {
      for (int j = 0; j < k; ++j) {
        buf[i] += in[i][seq[j]] * pow(10, j);
      }
    }
    sort(buf.begin(), buf.end());
    ans = min(ans, *(buf.rbegin()) - *(buf.begin()));
    return;
  }
  for (int i = 0; i < k; ++i) {
    if (seq[i] < 0) {
      seq[i] = l;
      solve(k, l + 1);
      seq[i] = -1;
    }
  }
}
int main(void) {
  int n, k;
  while (cin >> n >> k) {
    ans = 1000000;
    for (int i = 0; i < 100; ++i) {
      seq[i] = -1;
    }
    in.clear();
    in.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> in[i];
    }
    solve(k, 0);
    cout << ans << endl;
  }
  return 0;
}
