#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  map<long, long> cont;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cont[a[i]]++;
  }
  auto it = cont.end();
  --it;
  vector<long long> f(it->first + 1, 0);
  it = cont.begin();
  f[1] = cont[1] * 1;
  for (long long i = 2; i < f.size(); i++) {
    f[i] = max(f[i - 1], f[i - 2] + cont[i] * i);
  }
  cout << f[f.size() - 1];
}
