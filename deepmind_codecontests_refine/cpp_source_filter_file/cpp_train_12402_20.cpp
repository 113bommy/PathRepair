#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
struct Gaussian {
  long long no_of_bits = 20;
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
long long n, q, xorval = 0;
Gaussian store[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    xorval ^= x;
    store[i] = store[i - 1];
    store[i].push(x);
    store[i].eliminate();
  }
  if (xorval == 0)
    cout << "-1";
  else
    cout << store[n].redsize;
}
