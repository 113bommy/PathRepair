#include <bits/stdc++.h>
using namespace std;
int n, k, len, A[100005];
struct Set {
  long long spos, sneg, kpos, kneg;
  multiset<int> neg;
  multiset<int, greater<int> > leftneg;
  Set() {
    spos = 0;
    sneg = 0;
    kneg = 0;
  }
  void insert(int x) {
    if (x < 0) {
      x *= -1;
      sneg += x;
      neg.insert(x);
      kneg += x;
      if (neg.size() > k) {
        int y = *(neg.begin());
        kneg -= y;
        neg.erase(neg.begin());
        leftneg.insert(y);
      }
    } else {
      spos += x;
    }
  }
  void erase(int x) {
    if (x < 0) {
      x *= -1;
      sneg -= x;
      if (leftneg.find(x) != leftneg.end()) {
        leftneg.erase(leftneg.find(x));
      } else {
        neg.erase(neg.find(x));
        kneg -= x;
        if (leftneg.size() > 0) {
          int y = *(leftneg.begin());
          neg.insert(y);
          kneg += y;
          leftneg.erase(leftneg.begin());
        }
      }
    } else
      spos -= x;
  }
  long long query() { return spos - sneg + 2 * kneg; }
} F, S;
int main() {
  cin >> n >> len;
  for (int i = 0; i < n; ++i) cin >> A[i];
  cin >> k;
  long long maxi = -1e18;
  for (int i = 0; i < n; ++i) {
    F.insert(A[i]);
    if (i >= len) {
      F.erase(A[i - len]);
    }
    if (i >= len - 1) maxi = max(F.query(), maxi);
  }
  for (int i = 0; i < n; ++i) A[i] *= -1;
  for (int i = 0; i < n; ++i) {
    S.insert(A[i]);
    if (i >= len) {
      S.erase(A[i - len]);
    }
    if (i >= len - 1) maxi = max(S.query(), maxi);
  }
  cout << maxi << "\n";
  return 0;
}
