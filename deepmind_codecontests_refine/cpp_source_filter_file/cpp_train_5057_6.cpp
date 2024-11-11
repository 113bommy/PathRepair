#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int alphabet = 26;
const long long MAXINT = 1e15;
long long n, k, c = 0, ans = -1;
bool res = false;
vector<long long> v;
int main() {
  cin >> n >> k;
  long long raiz = sqrt(n) + 1;
  for (long long i = 1; i < raiz; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i != raiz) v.push_back(n / i);
    }
  }
  sort(v.begin(), v.end());
  if (k > v.size())
    cout << -1 << endl;
  else
    cout << v[k - 1] << endl;
  return 0;
}
