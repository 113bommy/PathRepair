#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n, a[300001], c, d, s, t;
long long b[2000001];
vector<long long> p;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
    s += a[i];
  }
  for (i = 0; i < n; i++) {
    k = s - a[i];
    if (k > 2000000) continue;
    b[a[i]]--;
    if (k % 2 == 0 && b[k / 2] > 0) {
      p.push_back(i + 1);
    }
    b[a[i]]++;
  }
  cout << p.size() << endl;
  for (i = 0; i < p.size(); i++) cout << p[i] << ' ';
}
