#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int s;
  cin >> n >> s;
  if (s > (long long int)n * ((long long int)n + 1) / 2 ||
      s < 1 + 2 * (n - 1)) {
    cout << "No" << endl;
    return 0;
  }
  if (s == (long long int)n * ((long long int)n + 1) / 2) {
    cout << "Yes" << endl;
    for (int i = 2; i <= n; i++) {
      cout << (i - 1);
      if (i < n) cout << " ";
    }
    cout << endl;
    return 0;
  }
  cout << "Yes" << endl;
  int x1 = 1, x2 = n - 1;
  while (x1 != x2) {
    int x = (x1 + x2) / 2;
    long long int pow = 1;
    long long int c = 1;
    long long int sum = 0;
    long long int ct = 1;
    while (1) {
      sum += pow * c;
      pow *= (long long int)x;
      c++;
      if (pow + ct >= n) {
        sum += (n - ct) * c;
        break;
      }
      ct += pow;
    }
    if (s >= sum)
      x2 = x;
    else
      x1 = x + 1;
  }
  long long int v[100001] = {};
  int h = 1;
  long long int pow = 1;
  for (int i = 1; i <= n; i++) {
    if (v[h] >= pow) {
      h++;
      pow *= ((long long int)x1 - 1);
    }
    v[h]++;
  }
  long long int s0 = 0;
  for (long long int i = 1; i <= h; i++) {
    s0 += (v[i] * i);
  }
  long long int mx[100001];
  mx[1] = 1;
  for (int i = 2; i <= h; i++) {
    mx[i] = min(mx[i - 1] * x1, (long long int)(1e6));
  }
  int h1 = 2, h2 = h;
  while (1) {
    v[h2]--;
    if (s0 - s <= h2 - h1) {
      v[h2 - s0 + s]++;
      break;
    }
    v[h1]++;
    s0 -= (h2 - h1);
    if (v[h1] == mx[h1]) h1++;
    if (v[h2] == 0) h2--;
  }
  int b[100001] = {};
  vector<int> ver[100001];
  int i0 = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 0; j < v[i]; j++) {
      ver[i].push_back(i0);
      i0++;
    }
  }
  int p = 1;
  int n0 = 0;
  for (int i = 2; i <= h; i++) {
    int p = ver[i - 1][0];
    for (int j = 0; j < ver[i].size(); j++) {
      cout << p;
      n0++;
      if (n0 < n - 1)
        cout << " ";
      else {
        cout << endl;
        return 0;
      }
      b[p]++;
      if (b[p] == x1) p++;
    }
  }
  return 0;
}
