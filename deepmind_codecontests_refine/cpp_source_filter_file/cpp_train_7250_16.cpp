#include <bits/stdc++.h>
using namespace std;
int v[26], n;
int best = 10, r[26];
set<long long> H;
bool was(int i) {
  vector<int> q(v, v + i + 1);
  sort((q).begin(), (q).end()),
      (q).erase(unique((q).begin(), (q).end()), (q).end());
  long long hsh = 0;
  for (int x : q) hsh = hsh * 1000000007 + x;
  if (H.count(hsh)) return true;
  H.insert(hsh);
  return false;
}
void go(int i) {
  if (i >= best || v[i] > n) return;
  if (was(i)) return;
  if (v[i] == n) {
    best = i;
    memcpy(r, v, (i + 1) * sizeof(int));
    return;
  }
  ++i;
  for (int j(0); j < i; ++j) {
    for (int k = 1; k <= 8; k *= 2) {
      v[i] = v[j] * k;
      if (k > 1) go(i);
      for (int l(0); l < i; ++l) {
        v[i] += v[l];
        go(i);
        v[i] -= v[l];
      }
    }
  }
}
void restore(int i) {
  printf("lea e%cx, ", char('a' + i));
  for (int j(0); j < i; ++j) {
    for (int k = 1; k <= 8; k *= 2) {
      int x = r[j] * k;
      if (k > 1 && x == r[i]) {
        printf("[%d * e%cx]\n", k, char('a' + j));
        return;
      }
      for (int l(0); l < i; ++l) {
        x += r[l];
        if (x == r[i]) {
          if (k > 1) {
            printf("[e%cx + %d * e%cx]\n", char('a' + l), k, char('a' + j));
            return;
          }
          printf("[e%cx + e%cx]\n", char('a' + l), char('a' + j));
          return;
        }
        x -= r[l];
      }
    }
  }
}
int main() {
  cin >> n;
  v[0] = 1;
  go(0);
  cout << best << endl;
  for (int i = 1; i <= best; ++i) restore(i);
  return 0;
}
