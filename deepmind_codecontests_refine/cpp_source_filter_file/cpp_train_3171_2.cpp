#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int data[4 * MAXN], h[MAXN];
void add(int p, int x, int s = 0, int e = 1e5 + 1, int id = 1) {
  if (e - s < 2) {
    h[s] += x;
    data[id] += x;
    return;
  }
  int mid = (s + e) / 2;
  if (p < mid) {
    add(p, x, s, mid, 2 * id + 0);
  } else {
    add(p, x, mid, e, 2 * id + 1);
  }
  data[id] = data[2 * id + 0] + data[2 * id + 1];
}
int get(int l, int r, int s = 0, int e = 1e5 + 1, int id = 1) {
  if (e <= l or r <= s) {
    return 0;
  }
  if (s >= l and e <= r) {
    return data[id];
  }
  int mid = (s + e) / 2;
  return get(l, r, s, mid, 2 * id + 0) + get(l, r, mid, e, 2 * id + 1);
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    add(i, 1);
    h[i] = 1;
  }
  int lefti = 0;
  int righti = n;
  bool reverse = false;
  for (int i = 0, type, p; i < q; i++) {
    cin >> type;
    if (type == 1) {
      cin >> p;
      if (reverse == false) {
        if (2 * p <= righti - lefti) {
          for (int j = 0; j < p; j++) {
            int cur = p + (p - j - 1);
            add(lefti + cur, h[j + lefti]);
          }
          lefti += p;
        } else {
          for (int j = p; j < righti - lefti; j++) {
            int cur = p + (p - j - 1);
            add(lefti + cur, h[j + lefti]);
          }
          righti = lefti + p;
          reverse = true;
        }
      } else {
        if (2 * p <= righti - lefti) {
          for (int j = 0; j < p; j++) {
            int cur = p + (p - i - 1);
            add(righti - 1 - cur, h[righti - j - 1]);
          }
          righti -= p;
        } else {
          for (int j = p; j < righti - lefti; j++) {
            int cur = p + (p - i - 1);
            add(righti - 1 - cur, h[righti - j - 1]);
          }
          lefti = righti - p;
          reverse = false;
        }
      }
    } else {
      int l, r;
      cin >> l >> r;
      if (!reverse) {
        cout << get(l + lefti, r + lefti) << endl;
      } else {
        cout << get(righti - r, righti - l) << endl;
      }
    }
  }
  return 0;
}
