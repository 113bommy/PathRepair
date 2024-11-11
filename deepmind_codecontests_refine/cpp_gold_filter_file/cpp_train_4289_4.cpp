#include <bits/stdc++.h>
using namespace std;
const long long dx[] = {4LL, 7LL};
vector<long long> lucky;
vector<long long> P;
int main() {
  {
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
      long long x = Q.front();
      for (int i = 0; i < 2; i++) {
        long long x1 = x * 10LL + dx[i];
        lucky.push_back(x1);
        if (x1 <= 1000000000LL) {
          Q.push(x1);
        }
      }
      Q.pop();
    }
  }
  for (long long i = 1, p = 1; i <= 14; i++) {
    P.push_back(p);
    p *= i;
  }
  int n, k;
  cin >> n >> k;
  k--;
  if (n < 13 && P[n] - 1 < k) {
    cout << -1;
    return (0);
  }
  list<int> L;
  for (int i = 1;; i++) {
    L.push_back(i);
    if (P[i] - 1 >= k) break;
  }
  vector<int> perm;
  for (int i = L.size() - 1; i >= 0; i--) {
    list<int>::iterator it = L.begin();
    while (k >= P[i]) {
      k -= P[i];
      it++;
    }
    perm.push_back(*it);
    L.erase(it);
  }
  int res = 0;
  for (int i = 0; lucky[i] < n - perm.size() + 1; i++) res++;
  for (int i = 0, pos = n - perm.size() + 1; i < perm.size(); i++, pos++) {
    int d = perm[i] - (i + 1);
    int truenum = pos + d;
    bool f1 = false, f2 = false;
    for (int i = 0; i < lucky.size(); i++) {
      if (truenum == lucky[i]) f1 = true;
      if (pos == lucky[i]) f2 = true;
    }
    if (f1 && f2) res++;
  }
  cout << res;
exit:
  return (0);
}
