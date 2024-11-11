#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long inf = 1e18;
double eps = 1e-2;
ifstream in("input.txt");
ofstream out("output.txt");
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n);
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    int j = a[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = a[j - 1];
    }
    if (s[i] == s[j]) j++;
    a[i] = j;
  }
  int val = a[n - 1];
  while (val > 0) {
    for (int i = val + 1; i < n - 1; i++) {
      if (a[i] == val) {
        cout << s.substr(0, val);
        return 0;
      }
    }
    val = a[val - 1];
  }
  cout << "Just a legend";
  return 0;
}
