#include <bits/stdc++.h>
using namespace std;
void addmod(int &a, long long b) {
  a = (a + b);
  if (a >= 1000000007) a -= 1000000007;
}
void mulmod(int &a, long long b) { a = (a * b) % 1000000007; }
template <class T>
bool domin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool domax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
int main() {
  long long n = gi(), k = gi(), m = gi();
  vector<pair<int, long long> > qfront, qback;
  long long totalsize = n, frontsize, backsize;
  for (int i = 0; i < n; i++) {
    int a = gi();
    if (qfront.empty() || qfront.back().first != a) {
      qfront.push_back({a, 1});
    } else {
      qfront.back().second++;
    }
    if (qfront.back().second >= k) qfront.pop_back(), totalsize -= k;
  }
  if (m == 1) return cout << totalsize << endl, 0;
  qback = qfront;
  int nn = qfront.size();
  int frontix = nn - 1, backix = 0;
  frontsize = backsize = totalsize;
  while (frontix >= 0 || backix < nn) {
    if (qfront[frontix].first == qback[backix].first) {
      frontsize -= qfront[frontix].second;
      backsize -= qback[backix].second;
      if (frontix == backix) {
        long long middlesz = (qfront[frontix].second * m) % k;
        if (middlesz > 0) {
          cout << frontsize + middlesz + backsize << endl;
          return 0;
        } else
          m = 2;
      } else {
        long long middlesz =
            (qfront[frontix].second + qback[backix].second) % k;
        if (middlesz > 0) {
          cout << frontsize + (m - 1) * middlesz + backsize +
                      (m - 2) * (max(0LL, totalsize - (totalsize - frontsize) -
                                              (totalsize - backsize)))
               << endl;
          return 0;
        }
      }
      frontix--, backix++;
    } else {
      int middlesz = max(
          0LL, totalsize - (totalsize - frontsize) - (totalsize - backsize));
      cout << frontsize + (m - 2) * middlesz + backsize << endl;
      return 0;
    }
  }
  cout << frontsize + backsize << endl;
  return 0;
}
