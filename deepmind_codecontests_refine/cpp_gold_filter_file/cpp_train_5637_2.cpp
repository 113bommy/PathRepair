#include <bits/stdc++.h>
using namespace std;
vector<long long int> v, vec[100007 + 3];
map<long long int, long long int> mep;
map<string, long long int> ms;
map<char, long long int> mc;
int a[100007 + 4], n, i, j, pf[100007 + 4];
void seive() {
  int x = sqrt(100007);
  for (int i = 2; i <= 100007; i += 2) pf[i] = 2;
  for (int i = 3; i <= 100007; i += 2) pf[i] = i;
  for (int i = 3; i <= x; i += 2) {
    if (pf[i] == i) {
      for (int j = i * i; j <= 100007; j += i) {
        if (pf[j] == j) pf[j] = i;
      }
    }
  }
}
int main() {
  seive();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<long long int, long long int> m;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      m[a[i] + a[j]]++;
    }
  }
  long long int ans = INT_MIN;
  for (auto i = m.begin(); i != m.end(); i++) {
    ans = max(ans, i->second);
  }
  cout << ans << endl;
}
