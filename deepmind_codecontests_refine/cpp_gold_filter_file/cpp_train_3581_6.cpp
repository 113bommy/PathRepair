#include <bits/stdc++.h>
using namespace std;
int seg[1 << 20] = {};
void update(int a, int x) {
  seg[a + (1 << 19) - 1] = x;
  a += (1 << 19) - 1;
  while (a > 0) {
    a = (a - 1) / 2;
    seg[a] = seg[a * 2 + 1] + seg[a * 2 + 2];
  }
}
int get(int a, int b, int k, int l, int r) {
  if (a > r || b < l) return 0;
  if (a <= l && r <= b) return seg[k];
  int le = get(a, b, k * 2 + 1, l, l + (r - l + 1) / 2 - 1);
  int ri = get(a, b, k * 2 + 2, l + (r - l + 1) / 2, r);
  return le + ri;
}
int main() {
  int n;
  vector<int> num(n);
  vector<int> prev(n);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < n; i++) {
    prev[num[i]] = i;
  }
  for (int i = 1; i < n; i++) {
    if (prev[i] > prev[i + 1]) {
      update(i, 1);
    } else {
      update(i, 0);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      int ret = get(a, b - 1, 0, 0, (1 << 19) - 1);
      cout << ret + 1 << endl;
    } else {
      int a, b;
      cin >> a >> b;
      int g = num[a - 1];
      int h = num[b - 1];
      swap(prev[g], prev[h]);
      swap(num[a - 1], num[b - 1]);
      if (g > 1) {
        if (prev[g - 1] > prev[g]) {
          update(g - 1, 1);
        } else {
          update(g - 1, 0);
        }
      }
      if (g < n) {
        if (prev[g] > prev[g + 1]) {
          update(g, 1);
        } else {
          update(g, 0);
        }
      }
      if (h > 1) {
        if (prev[h - 1] > prev[h]) {
          update(h - 1, 1);
        } else {
          update(h - 1, 0);
        }
      }
      if (h < n) {
        if (prev[h] > prev[h + 1]) {
          update(h, 1);
        } else {
          update(h, 0);
        }
      }
    }
  }
}
