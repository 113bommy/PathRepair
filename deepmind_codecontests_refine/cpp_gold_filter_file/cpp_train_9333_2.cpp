#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
const int mod = (int)1e9 + 7;
vector<long long> v;
long long cnt;
long long x, d;
void make(long long n) {
  for (int i = 0; i < 40; i++) {
    if ((n >> i) & 1) {
      for (int j = 1; j <= i; j++) v.push_back(x);
      cnt++;
      x += d;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n >> d;
  x = 1;
  make(n);
  int b = 0;
  while (cnt > 1) {
    n = cnt;
    cnt = 0;
    b++;
    make(n);
  }
  v.push_back(x + d);
  cout << v.size() << endl;
  for (long long j : v) cout << j << " ";
  return 0;
}
