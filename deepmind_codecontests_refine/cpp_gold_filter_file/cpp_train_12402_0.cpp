#include <bits/stdc++.h>
using namespace std;
vector<long long> val(100000 + 5);
struct Gaussian {
  long long no_of_bits = 32;
  vector<long long> v;
  long long set, origsize = 0, redsize = 0;
  void push(long long val) {
    origsize++;
    if (val) v.push_back(val);
  }
  void clear() {
    v.clear();
    set = 0, redsize = 0;
  }
  void eliminate() {
    set = redsize = 0;
    for (long long bit = 0; bit <= no_of_bits; bit++) {
      bool check = false;
      for (long long i = redsize; i < v.size(); i++) {
        if ((v[i] >> bit) & 1) {
          swap(v[i], v[redsize]);
          check = true;
          break;
        }
      }
      if (check) {
        for (long long i = redsize + 1; i < v.size(); i++) {
          if ((v[i] >> bit) & 1) v[i] ^= v[redsize];
        }
        redsize++;
      }
    }
    v.resize(redsize);
    for (auto it : v) set |= it;
  }
  Gaussian& operator=(Gaussian& orig) {
    v = orig.v;
    set = orig.set;
    redsize = orig.redsize;
    origsize = orig.origsize;
    return *this;
  }
};
long long modexpo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  val.resize(n);
  Gaussian temp;
  long long xorr = 0;
  for (long long i = 0; i < n; i++)
    cin >> val[i], xorr = xorr ^ val[i], temp.push(val[i]);
  if (xorr == 0)
    cout << -1 << "\n";
  else {
    temp.eliminate();
    cout << temp.redsize << "\n";
  }
  return 0;
}
