#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<int> A(H), B(H);
  for (int i = 0; i < H; i++) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }
  map<int, int> mp;
  multiset<int> res;
  for (int i = 0; i < W; i++) {
    mp[i] = i;
    res.insert(0);
  }
  for (int i = 0; i < H; i++) {
    auto it = mp.lower_bound(A[i]);
    int n = -1;
    while (it != mp.end() && it->first < B[i] + 2) {
      int x = it->first - it->second;
      n = max(n, it->second);
      res.erase(res.find(x));
      mp.erase(it++);
    }
    if (n != -1 && B[i] + 1 < W) {
      res.insert(B[i] + 1 - n);
      mp[B[i] + 1] = n;
    }
    if (!res.empty()) {
      cout << *res.begin() + i + 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
