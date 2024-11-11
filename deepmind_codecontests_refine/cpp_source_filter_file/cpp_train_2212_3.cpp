#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mod = -1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k = 0, m = 0;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] & 1)
        k++;
      else
        m++;
    }
    k %= 2;
    m %= 2;
    k += m;
    sort(((v).begin()), ((v).end()));
    long long x = 0;
    for (long long i = 0; i < n - 1; i++)
      if (v[i + 1] - v[i] == 1) x++;
    if (k == 1)
      cout << "NO";
    else {
      k /= 2;
      if (k == x or k == 0)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << "\n";
  }
}
