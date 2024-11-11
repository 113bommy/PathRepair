#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k, d, a, m;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k >> d;
    long long int ar[n];
    for (int i = 0; i < n; i++) {
      cin >> a;
      ar[i] = a;
    }
    m = k;
    for (int i = 0; i < n - d + 1; i++) {
      set<int> s;
      for (int j = i; j < i + d; j++) {
        s.insert(ar[j]);
      }
      long long int c = s.size();
      m = min(m, c);
    }
    cout << m;
  }
}
