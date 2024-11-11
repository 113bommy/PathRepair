#include <bits/stdc++.h>
using namespace std;
int a[7005], b[7005], ans1[7005], ans2[7005], n, cnt1[7005], cnt2[7005];
int ind(int x, int p) {
  x -= p;
  x += n;
  if (x != n) {
    x %= n;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, k1, k2;
  cin >> n >> k1;
  for (i = 2; i <= n; i++) {
    ans1[i] = -1;
    ans2[i] = -1;
  }
  deque<pair<int, int> > d;
  for (i = 1; i <= k1; i++) {
    cin >> a[i];
    ans1[ind(1, a[i])] = 1;
    d.push_back({ind(1, a[i]), 1});
  }
  cin >> k2;
  for (i = 1; i <= k2; i++) {
    cin >> b[i];
    ans2[ind(1, b[i])] = 1;
    d.push_back({ind(1, b[i]), 2});
  }
  while (d.size() > 0) {
    pair<int, int> cur = d[0];
    d.pop_front();
    if (cur.second == 1) {
      if (ans1[cur.first] == 1) {
        for (i = 1; i <= k1; i++) {
          cnt2[ind(cur.first, b[i])]++;
          if (cnt2[ind(cur.first, b[i])] == k2 &&
              ans2[ind(cur.first, b[i])] == -1) {
            ans2[ind(cur.first, b[i])] = 0;
            d.push_back({ind(cur.first, b[i]), 2});
          }
        }
      } else {
        for (i = 1; i <= k1; i++) {
          if (ans2[ind(cur.first, b[i])] == -1) {
            ans2[ind(cur.first, b[i])] = 1;
            d.push_back({ind(cur.first, b[i]), 2});
          }
        }
      }
    } else {
      if (ans2[cur.first] == 1) {
        for (i = 1; i <= k2; i++) {
          cnt1[ind(cur.first, a[i])]++;
          if (cnt1[ind(cur.first, a[i])] == k1 &&
              ans1[ind(cur.first, a[i])] == -1) {
            ans1[ind(cur.first, a[i])] = 0;
            d.push_back({ind(cur.first, a[i]), 1});
          }
        }
      } else {
        for (i = 1; i <= k2; i++) {
          if (ans1[ind(cur.first, a[i])] == -1) {
            ans1[ind(cur.first, a[i])] = 1;
            d.push_back({ind(cur.first, a[i]), 1});
          }
        }
      }
    }
  }
  for (i = 2; i <= n; i++) {
    cout << (ans1[i] == -1 ? "Loop " : (ans1[i] == 0 ? "Lose " : "Win "));
  }
  cout << "\n";
  for (i = 2; i <= n; i++) {
    cout << (ans2[i] == -1 ? "Loop " : (ans2[i] == 0 ? "Lose " : "Win "));
  }
  return 0;
}
