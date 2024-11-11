#include <bits/stdc++.h>
using namespace std;
pair<int, int> pp[5], p[5], q[5];
int s;
map<char, char> MP;
int Ok() {
  if (q[1].second == s && q[2].second == s && q[3].second == s) {
    if (q[1].first + q[2].first + q[3].first == s) return 1;
  }
  if (q[1].first == s && q[2].first == s && q[3].first == s) {
    if (q[1].second + q[2].second + q[3].second == s) return 2;
  }
  if (q[1].second == s) {
    if (q[2].second + q[3].second == s && q[2].first + q[1].first == s &&
        q[3].first + q[1].first == s)
      return 3;
  }
  if (q[1].first == s) {
    if (q[2].first + q[3].first == s && q[2].second + q[1].second == s &&
        q[3].second + q[1].second == s)
      return 4;
  }
  return 0;
}
int Okk() {
  if (q[1].second == s && q[2].second == s && q[3].second == s) {
    if (q[1].first + q[2].first + q[3].first == s) {
      int x = 1;
      for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= q[i].first; j++) {
          for (int k = 1; k <= s; k++) {
            cout << MP[(char)(i + 64)];
          }
          printf("\n");
        }
      }
      return 1;
    }
  }
  if (q[1].first == s && q[2].first == s && q[3].first == s) {
    if (q[1].second + q[2].second + q[3].second == s) {
      for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= q[1].second; j++) cout << MP['A'];
        for (int j = 1; j <= q[2].second; j++) cout << MP['B'];
        for (int j = 1; j <= q[3].second; j++) cout << MP['C'];
        printf("\n");
      }
      return 2;
    }
  }
  if (q[1].second == s) {
    if (q[2].second + q[3].second == s && q[2].first + q[1].first == s &&
        q[3].first + q[1].first == s) {
      for (int i = 1; i <= q[1].first; i++) {
        for (int j = 1; j <= s; j++) cout << MP['A'];
        printf("\n");
      }
      for (int i = 1; i <= q[2].first; i++) {
        for (int j = 1; j <= q[2].second; j++) cout << MP['B'];
        for (int j = 1; j <= q[3].second; j++) cout << MP['C'];
        printf("\n");
      }
      return 3;
    }
  }
  if (q[1].first == s) {
    if (q[2].first + q[3].first == s && q[2].second + q[1].second == s &&
        q[3].second + q[1].second == s) {
      for (int i = 1; i <= q[2].first; i++) {
        for (int j = 1; j <= q[1].second; j++) cout << MP['A'];
        for (int j = 1; j <= q[2].second; j++) cout << MP['B'];
        printf("\n");
      }
      for (int i = 1; i <= q[3].first; i++) {
        for (int j = 1; j <= q[1].second; j++) cout << MP['A'];
        for (int j = 1; j <= q[3].second; j++) cout << MP['C'];
        printf("\n");
      }
      return 4;
    }
  }
  return 0;
}
int Solve() {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        if (i == 1) swap(q[1].first, q[1].second);
        if (j == 1) swap(q[2].first, q[2].second);
        if (k == 1) swap(q[3].first, q[3].second);
        int ret = Ok();
        if (ret) return ret;
      }
    }
  }
  return 0;
}
int Solve2() {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        q[1] = p[1];
        q[2] = p[2];
        q[3] = p[3];
        if (i == 1) swap(q[1].first, q[1].second);
        if (j == 1) swap(q[2].first, q[2].second);
        if (k == 1) swap(q[3].first, q[3].second);
        int ret = Okk();
        if (ret) return ret;
      }
    }
  }
  return 0;
}
int go() {
  int ar[5];
  for (int i = 1; i <= 3; i++) ar[i] = i;
  for (int i = 1; i <= 3; i++) MP[(char)(i + 64)] = (char)(i + 64);
  do {
    for (int i = 1; i <= 3; i++) p[ar[i]] = pp[i];
    for (int i = 1; i <= 3; i++) MP[(char)(i + 64)] = (char)(ar[i] + 64);
    int ret = Solve();
    if (ret) return ret;
    MP.clear();
  } while (next_permutation(ar + 1, ar + 4));
  return 0;
}
int pre[500005 + 5];
int main() {
  int i, j, k, a, b, c, d, x, y;
  vector<int> v;
  int sm = 0;
  for (int i = 0; i <= 400; i++) pre[i] = i * i;
  for (int i = 1; i <= 3; i++) {
    cin >> a >> b;
    sm += (a * b);
    v.push_back(a);
    v.push_back(b);
    pp[i] = make_pair(a, b);
  }
  if (binary_search(pre, pre + 400, sm) == 0) {
    cout << -1 << "\n";
    return 0;
  }
  s = sqrt(sm);
  int res = go();
  if (!res)
    cout << -1 << endl;
  else {
    cout << s << "\n";
    int rr = Solve2();
  }
  return 0;
}
