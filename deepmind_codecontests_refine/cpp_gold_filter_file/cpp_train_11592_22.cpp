#include <bits/stdc++.h>
using namespace std;
const int D = 4;
struct choice {
  bool used[D * D];
  int step;
  long long a1, a2, a3, a4, a5, a6, a8, a9;
  long long b1, b2, b3, b4, b5, b6, b7, b8;
};
int n;
long long s;
long long a[D * D];
long long a_temp[D][D];
bool ok_trivial() {
  long long *tmp = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a_temp[i][j] = *tmp;
      tmp++;
    }
  }
  long long ss;
  for (int i = 0; i < n; i++) {
    ss = 0;
    for (int j = 0; j < n; j++) ss += a_temp[i][j];
    if (ss != s) return false;
  }
  for (int j = 0; j < n; j++) {
    ss = 0;
    for (int i = 0; i < n; i++) ss += a_temp[i][j];
    if (ss != s) return false;
  }
  ss = 0;
  for (int i = 0; i < n; i++) ss += a_temp[i][i];
  if (ss != s) return false;
  ss = 0;
  for (int i = 0; i < n; i++) ss += a_temp[i][n - 1 - i];
  if (ss != s) return false;
  return true;
}
void solve_trivial() {
  sort(a, a + n * n);
  if (ok_trivial()) {
    cout << s;
    for (int i = 0; i < n; i++) {
      cout << '\n';
      for (int j = 0; j < n; j++) cout << a_temp[i][j] << ' ';
    }
    return;
  }
  while (next_permutation(a, a + n * n)) {
    if (ok_trivial()) {
      cout << s;
      for (int i = 0; i < n; i++) {
        cout << '\n';
        for (int j = 0; j < n; j++) cout << a_temp[i][j] << ' ';
      }
      return;
    }
  }
}
int fnd(const choice &C, long long val) {
  for (int i = 0; i < n * n; i++) {
    if (!C.used[i] && a[i] == val) return i;
  }
  return -1;
}
bool ok(choice &C) {
  int ind;
  ind = fnd(C, s - (C.a1 + C.a5 + C.a9));
  if (ind == -1) return false;
  C.used[ind] = true;
  C.b3 = a[ind];
  ind = fnd(C, s - (C.b1 + C.b2 + C.b3));
  if (ind == -1) return false;
  C.used[ind] = true;
  C.b4 = a[ind];
  ind = fnd(C, s - (C.a8 + C.a9 + C.b4));
  if (ind == -1) return false;
  C.used[ind] = true;
  C.b5 = a[ind];
  ind = fnd(C, s - (C.a1 + C.a4 + C.b5));
  if (ind == -1) return false;
  C.used[ind] = true;
  C.b6 = a[ind];
  ind = fnd(C, s - (C.a2 + C.a5 + C.a8));
  if (ind == -1) return false;
  C.used[ind] = true;
  C.b7 = a[ind];
  ind = fnd(C, s - (C.a3 + C.a6 + C.a9));
  if (ind == -1) return false;
  C.used[ind] = true;
  C.b8 = a[ind];
  {
    cout << s << '\n';
    cout << C.a1 << ' ' << C.a4 << ' ' << C.b5 << ' ' << C.b6 << '\n';
    cout << C.a2 << ' ' << C.a5 << ' ' << C.a8 << ' ' << C.b7 << '\n';
    cout << C.a3 << ' ' << C.a6 << ' ' << C.a9 << ' ' << C.b8 << '\n';
    cout << C.b1 << ' ' << C.b2 << ' ' << C.b4 << ' ' << C.b3;
  }
  return true;
}
void solve_4() {
  sort(a, a + n * n);
  choice seed;
  seed.step = 0;
  for (int i = 0; i < n * n; i++) seed.used[i] = false;
  stack<choice> all;
  all.push(seed);
  while (!all.empty()) {
    seed = all.top();
    all.pop();
    if (seed.step == 0) {
      int n2 = n * n;
      for (int i1 = 0; i1 < n2; i1++) {
        for (int i2 = 0; i2 < n2; i2++) {
          for (int i3 = 0; i3 < n2; i3++) {
            if (i1 == i2 || i2 == i3 || i1 == i3) continue;
            choice nova = seed;
            nova.used[i1] = true;
            nova.used[i2] = true;
            nova.used[i3] = true;
            nova.step = 1;
            nova.a1 = a[i1];
            nova.a2 = a[i2];
            nova.a3 = a[i3];
            int ind = fnd(nova, s - (nova.a1 + nova.a2 + nova.a3));
            if (ind == -1) continue;
            nova.b1 = a[ind];
            nova.used[ind] = true;
            all.push(nova);
          }
        }
      }
    } else if (seed.step == 1) {
      int n2 = n * n;
      for (int i1 = 0; i1 < n2; i1++) {
        if (seed.used[i1]) continue;
        for (int i2 = 0; i2 < n2; i2++) {
          if (seed.used[i2]) continue;
          for (int i3 = 0; i3 < n2; i3++) {
            if (seed.used[i3]) continue;
            if (i1 == i2 || i2 == i3 || i1 == i3) continue;
            choice nova = seed;
            nova.used[i1] = true;
            nova.used[i2] = true;
            nova.used[i3] = true;
            nova.step = 2;
            nova.a4 = a[i1];
            nova.a5 = a[i2];
            nova.a6 = a[i3];
            int ind = fnd(nova, s - (nova.a4 + nova.a5 + nova.a6));
            if (ind == -1) continue;
            nova.b2 = a[ind];
            nova.used[ind] = true;
            all.push(nova);
          }
        }
      }
    } else {
      int n2 = n * n;
      for (int i1 = 0; i1 < n2; i1++) {
        if (seed.used[i1]) continue;
        for (int i2 = 0; i2 < n2; i2++) {
          if (seed.used[i2]) continue;
          if (i1 == i2) continue;
          choice nova = seed;
          nova.used[i1] = true;
          nova.used[i2] = true;
          nova.a8 = a[i1];
          nova.a9 = a[i2];
          if (ok(nova)) {
            return;
          }
        }
      }
    }
  }
  cout << "Very end!\n";
}
int main() {
  cin >> n;
  long long s_temp = 0;
  for (int i = 0; i < n * n; i++) {
    cin >> a[i];
    s_temp += a[i];
  }
  s_temp /= n;
  s = s_temp;
  if (n <= 3)
    solve_trivial();
  else
    solve_4();
  return 0;
}
