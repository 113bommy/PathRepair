#include <bits/stdc++.h>
using namespace std;
int n, k;
int q[105], s[105], p[105], tmp[105];
int work1() {
  int cnt = 1;
  while (cnt <= k) {
    memcpy(tmp, p, sizeof(p));
    int f = n;
    for (int i = 1; i <= n; i++) {
      p[i] = tmp[q[i]];
      if (p[i] == s[i]) f--;
    }
    if (!f) return cnt;
    cnt++;
  }
  return -1;
}
int work2() {
  int cnt = 1;
  while (cnt <= k) {
    memcpy(tmp, p, sizeof(p));
    int f = n;
    for (int i = 1; i <= n; i++) {
      p[q[i]] = tmp[i];
      if (p[q[i]] == s[q[i]]) f--;
    }
    if (!f) return cnt;
    cnt++;
  }
  return -1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
  int eq = true;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    p[i] = i;
    if (s[i] != i) eq = false;
  }
  if (eq) {
    cout << "NO" << endl;
    return 0;
  }
  int as1 = work1();
  for (int i = 1; i <= n; i++) p[i] = i;
  int as2 = work2();
  if (as1 == 1 && as2 == 1) {
    if (k == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  if (as1 != -1) {
    if ((k - as1) == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (as2 != -1) {
    if ((k - as2) % 2 == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
