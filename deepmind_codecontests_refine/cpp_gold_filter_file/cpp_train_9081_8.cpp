#include <bits/stdc++.h>
using namespace std;
long long a[200010], b[200010];
vector<pair<char, long long> > p2;
void print() {
  long long ap = 0, ar = 0;
  for (int i = 0; i < p2.size(); i++) {
    if (p2[i].first == 'P') ap += p2[i].second;
    if (p2[i].first == 'R') ar += p2[i].second;
  }
  if (ap > 200000) {
    puts("BIG");
    printf("%lld\n", ap);
  } else {
    puts("SMALL");
    printf("%lld\n", ap + ar);
    reverse(p2.begin(), p2.end());
    for (int i = 0; i < p2.size(); i++) {
      printf("%s", string(p2[i].second, p2[i].first).c_str());
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
  }
  vector<long long> va(a, a + n), vb(b, b + n);
  if (n == 1) {
    if (a[0] != b[0]) {
      puts("IMPOSSIBLE");
    } else {
      puts("SMALL\n0\n");
    }
    return 0;
  }
  if (n == 2) {
    while (min(a[0], a[1]) != min(b[0], b[1]) ||
           max(a[0], a[1]) != max(b[0], b[1])) {
      if (min(b[0], b[1]) <= 0) break;
      if (b[0] > b[1]) {
        swap(b[0], b[1]);
        p2.push_back(make_pair('R', 1));
      } else if (b[0] < b[1]) {
        if (min(a[0], a[1]) == b[0]) {
          if (max(a[0], a[1]) > b[1] || (b[1] - max(a[0], a[1])) % b[0]) break;
          long long k = (b[1] - max(a[0], a[1])) / b[0];
          p2.push_back(make_pair('P', k));
          b[1] -= k * b[0];
        } else {
          long long k = (b[1] - 1) / b[0];
          p2.push_back(make_pair('P', k));
          b[1] -= k * b[0];
        }
      } else {
        break;
      }
    }
    if (min(a[0], a[1]) == min(b[0], b[1]) &&
        max(a[0], a[1]) == max(b[0], b[1])) {
      if (a[0] != b[0]) p2.push_back(make_pair('R', 1));
      print();
    } else {
      puts("IMPOSSIBLE");
    }
    return 0;
  }
  while (1) {
    for (int i = 0; i < n; i++) {
      if (vb[i] <= 0) {
        puts("IMPOSSIBLE");
        return 0;
      }
    }
    int ok = 0;
    for (int i = 0; i < 2; i++) {
      if (va == vb) {
        ok = i + 1;
        break;
      }
      reverse(vb.begin(), vb.end());
    }
    if (ok) {
      if (ok == 2) p2.push_back(make_pair('R', 1));
      print();
      return 0;
    }
    ok = 0;
    for (int i = 0; i < 2; i++) {
      int f = 0;
      for (int j = 1; j < n; j++) {
        if (vb[j - 1] > vb[j]) f = 1;
      }
      if (!f) {
        ok = i + 1;
        break;
      }
      reverse(vb.begin(), vb.end());
    }
    if (!ok) {
      puts("IMPOSSIBLE");
      return 0;
    }
    if (ok == 2) p2.push_back(make_pair('R', 1));
    for (int i = n - 1; i > 0; i--) {
      vb[i] -= vb[i - 1];
    }
    p2.push_back(make_pair('P', 1));
  }
  return 0;
}
