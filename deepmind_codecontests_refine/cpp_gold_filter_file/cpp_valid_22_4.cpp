#include <bits/stdc++.h>
using namespace std;
int n, k, tt[40], qq[10];
long long int m[10][41];
vector<int> ss[10];
int check(int c, long long int s) {
  if (c == k) {
    int i;
    for (i = 0; i <= n; i++) {
      if (s == (((1LL << (n - i)) - 1) << i)) return 1;
    }
    return 0;
  }
  int i;
  int z = ss[c].size() - qq[c] - __builtin_popcountll(s & m[c][0]);
  s &= ~m[c][0], s |= m[c][z];
  for (i = 0; i <= qq[c]; i++) {
    if (!check(c + 1, s)) return 0;
    if (i < qq[c]) s ^= (1LL << ss[c][z + i]);
  }
  return 1;
}
int main() {
  int i, j;
  int q;
  cin >> n >> k;
  for (i = 0; i < n; i++) tt[i] = -1;
  for (i = 0; i < k; i++) {
    cin >> q;
    ss[i].resize(q);
    for (j = 0; j < q; j++) {
      cin >> ss[i][j], ss[i][j]--;
      if (tt[ss[i][j]] == -1) tt[ss[i][j]] = i;
    }
  }
  if (n == 1) {
    cout << "ACCEPTED" << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (tt[i] == -1) {
      cout << "REJECTED" << endl;
      return 0;
    } else
      qq[tt[i]]++;
  }
  for (i = 0; i < k; i++) {
    long long int a = 0;
    for (j = 0; j < ss[i].size(); j++) a |= (1LL << ss[i][j]);
    for (j = 0; j <= ss[i].size(); j++) {
      m[i][j] = a;
      if (j < ss[i].size()) a ^= (1LL << ss[i][j]);
    }
  }
  if (check(0, 0)) {
    cout << "ACCEPTED" << endl;
    return 0;
  } else {
    cout << "REJECTED" << endl;
    return 0;
  }
  return 0;
}
