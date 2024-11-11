#include <bits/stdc++.h>
using namespace std;
char nn = '\n';
char ss = ' ';
const long long int mod = 1e9 + 7;
long long int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long int n, count = 0;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort((v).begin(), (v).end());
    if (n == 1 || n == 2)
      cout << "0" << nn;
    else {
      for (int i = 1; i < n - 1; i++) {
        if (v[i] > v[0] && v[i] < v[n - 1]) count++;
      }
      cout << count << nn;
    }
  }
  return 0;
}
