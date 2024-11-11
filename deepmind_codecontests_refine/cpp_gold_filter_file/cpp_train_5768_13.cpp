#include <bits/stdc++.h>
using namespace std;
class cht {
  vector<long long> xmin;
  vector<long long> kmas;
  vector<long long> bmas;

 public:
  cht(int k) {
    xmin.push_back(0);
    kmas.push_back(k);
    bmas.push_back(0);
  }
  void add(long long k, long long b) {
    while (!xmin.empty() &&
           kmas.back() * xmin.back() + bmas.back() >= k * xmin.back() + b) {
      xmin.pop_back();
      kmas.pop_back();
      bmas.pop_back();
    }
    long long nxmin =
        (b - bmas.back() + (kmas.back() - k - 1)) / (kmas.back() - k);
    if (nxmin <= 10000000000LL) {
      xmin.push_back(nxmin);
      kmas.push_back(k);
      bmas.push_back(b);
    }
  }
  long long getMaxIn(long long x) {
    int ind = upper_bound(xmin.begin(), xmin.end(), x) - xmin.begin() - 1;
    return kmas[ind] * x + bmas[ind];
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<long long> d(n);
  cht st(b[0]);
  for (int i = 1; i < n; i++) {
    d[i] = st.getMaxIn(a[i]);
    st.add(b[i], d[i]);
  }
  cout << d[n - 1];
  return 0;
}
