#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000000;
vector<long long> mask[63], ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    long long x, tmp, msb = -1;
    cin >> x;
    tmp = x;
    while (tmp) tmp >>= 1, msb++;
    mask[msb].push_back(x);
  }
  long long cur = 0;
  bool ok;
  for (int i = 0; i < N; i++) {
    ok = false;
    for (int j = 0; j < 63; j++) {
      if (!(cur & (1LL << j)) && !mask[j].empty()) {
        ans.push_back(mask[j].back());
        cur ^= mask[j].back();
        mask[j].pop_back();
        ok = true;
        break;
      }
    }
    if (!ok) break;
  }
  if (!ok)
    cout << "No\n";
  else {
    cout << "Yes\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i + 1 < ans.size())
        cout << " ";
      else
        cout << '\n';
    }
  }
}
