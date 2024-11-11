#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
template <class T>
inline T sqr(T a) {
  return a * a;
}
int n, s;
vector<int> v;
bool ok() {
  int r[4] = {0}, c[4] = {0}, d1 = 0, d2 = 0;
  for (int i = 0; i < n; ++i) {
    d1 += v[n * i + i];
    d2 += v[n * i + n - i - 1];
    for (int j = 0; j < n; ++j) {
      r[i] += v[n * i + j];
      c[j] += v[n * i + j];
    }
  }
  for (int i = 0; i < n; ++i)
    if (r[i] != s || c[i] != s) return 0;
  return d1 == s && d2 == s;
}
void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << v[n * i + j] << " ";
    }
    cout << endl;
  }
}
int main() {
  scanf("%d", &n);
  int sum = 0;
  v.resize(n * n);
  for (int i = 0; i < n * n; ++i) {
    scanf("%d", &v[i]);
    sum += v[i];
  }
  s = sum / n;
  cout << s << endl;
  for (int i = 0; i < (1 << 21); ++i) {
    random_shuffle((v).begin(), (v).end());
    if (!ok()) continue;
    print();
    break;
  }
  return 0;
}
