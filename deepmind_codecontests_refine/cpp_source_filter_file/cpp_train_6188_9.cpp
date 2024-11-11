#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a, b;
int t[200];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    long long int w;
    cin >> w;
    long long int k = (w * a) / b;
    long long int wart = (k * b) / a;
    cout << w - wart << ' ';
  }
}
