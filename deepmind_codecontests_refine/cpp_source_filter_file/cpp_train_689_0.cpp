#include <bits/stdc++.h>
using namespace std;
long long n, m, kol, d;
vector<long long> v;
int main() {
  cin >> n >> d;
  kol = n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    v.push_back(m);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j <= n - 1; j++) {
      if (v[j] - v[i] <= d)
        if (kol >= n + i - j - 1) kol = n + i - j - 1;
    }
  }
  cout << kol;
}
