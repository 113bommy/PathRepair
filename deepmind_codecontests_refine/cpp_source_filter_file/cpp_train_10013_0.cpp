#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> a >> b;
  cout << min(b - (n + a), min(min(a, b), n)) + 1;
}
