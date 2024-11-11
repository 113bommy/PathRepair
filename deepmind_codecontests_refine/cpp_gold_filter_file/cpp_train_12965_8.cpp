#include <bits/stdc++.h>
using namespace std;
long long int expo(long long int x, long long int n, long long int M) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = (res * x) % M;
    }
    x = (x * x) % M;
    n /= 2;
  }
  return res;
}
long long int maxn = 105, c = 0;
vector<long long int> minprime(maxn + 1, 1), sei(maxn + 1, 1), v;
void seive() {
  for (long long int i = 0; i <= maxn; i++) minprime[i] = i;
  sei[0] = sei[1] = 0;
  for (long long int i = 2; i * i <= maxn; i++) {
    if (sei[i] == 1) {
      for (long long int j = i * i; j <= maxn; j += i) {
        sei[j] = 0;
        minprime[j] = min(minprime[j], i);
      }
    }
  }
  for (long long int i = 0; i <= maxn; i++) {
    if (i >= 2 && sei[i]) {
      v.push_back(i);
    }
  }
}
void solve() {
  long long int c = 0, z = 0;
  for (long long int i = 0; i < v.size(); i++) {
    if (c < 15) {
      cout << v[i] << endl;
      cout.flush();
      string x;
      cin >> x;
      z += (x == "yes");
      if (v[i] * v[i] <= 100) {
        cout << v[i] * v[i] << endl;
        cout.flush();
        string x;
        cin >> x;
        z += (x == "yes");
      }
      c++;
    } else
      break;
  }
  if (z <= 1)
    cout << "prime" << endl;
  else
    cout << "composite" << endl;
  cout.flush();
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1, test = 0;
  seive();
  while (t--) {
    solve();
  }
}
