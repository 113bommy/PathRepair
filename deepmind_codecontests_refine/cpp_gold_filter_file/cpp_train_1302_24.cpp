#include <bits/stdc++.h>
using namespace std;
vector<int> mult(vector<int> a, vector<int> b) {
  int n = a.size();
  vector<int> c(n);
  for (int i = 0; i < n; i++) c[i] = a[b[i]];
  return c;
}
bool commutative(vector<int> a, vector<int> b) {
  return mult(a, b) == mult(b, a);
}
int calc(vector<int> a) {
  int n = a.size();
  vector<int> b(n, 0);
  int result = 0;
  while (true) {
    result += commutative(a, b);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (b[i] < n - 1) {
        b[i]++;
        ok = true;
        break;
      } else
        b[i] = 0;
    }
    if (!ok) break;
  }
  return result;
}
vector<int> cyclen(vector<int> a) {
  int n = a.size();
  vector<bool> used(n, false);
  vector<int> result;
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    int len = 0;
    int j = i;
    while (!used[j]) {
      used[j] = true;
      j = a[j];
      len++;
    }
    result.push_back(len);
  }
  sort(result.begin(), result.end());
  return result;
}
void investigate() {
  int n = 7;
  vector<int> p(n);
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < 100; i++) {
    vector<int> c = cyclen(p);
    if (c.size() != 4 || c[0] != 1 || c[1] != 2 || c[2] != 2) {
      random_shuffle(p.begin(), p.end());
      continue;
    }
    int cnt = calc(p);
    for (int x : c) cout << x << " ";
    cout << ": " << cnt << endl;
    random_shuffle(p.begin(), p.end());
  }
}
const long long M = 1000000007;
int main() {
  int p, k;
  cin >> p >> k;
  if (k <= 1) {
    long long ans = 1;
    for (int i = 1; i < p + k; i++) {
      ans = (ans * p) % M;
    }
    cout << ans << endl;
    return 0;
  }
  vector<int> a(p);
  for (int i = 0; i < p; i++) {
    a[i] = int(k * 1ll * i % p);
  }
  vector<int> c = cyclen(a);
  long long ans = 1;
  for (int i = 0; i < c.size() - 1; i++) ans = (ans * p) % M;
  cout << ans << endl;
  return 0;
}
