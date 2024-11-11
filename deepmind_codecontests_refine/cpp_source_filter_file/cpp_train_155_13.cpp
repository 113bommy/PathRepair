#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> > q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (k < n + 1 || n <= 4) {
    cout << -1 << endl;
    exit(0);
  }
  cout << a << " " << c << " ";
  for (long long int i = 1; i < n; i++) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (long long int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << b << " " << d << endl;
}
