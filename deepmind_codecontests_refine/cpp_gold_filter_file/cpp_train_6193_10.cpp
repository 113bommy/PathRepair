#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXN = 1000006;
const long double eps = 1e-13;
long double licz(pair<int, int> A, long double t) {
  return t / A.first + 1. / A.second;
}
bool better(pair<int, int> A, pair<int, int> B, long double t) {
  if (t > eps) return licz(A, t) < licz(B, t) - eps;
  if (A.second == B.second) return A.first > B.first;
  return A.second > B.second;
}
long double get(pair<int, int> A, pair<int, int> B) {
  return (1. / B.second - 1. / A.second) / (1. / A.first - 1. / B.first);
}
void solve() {
  int n;
  scanf("%d", &n);
  vector<pair<pair<int, int>, int> > A(n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d%d", &A[i].first.first, &A[i].first.second);
    A[i].second = i;
  }
  sort((A).begin(), (A).end());
  stack<pair<int, long double> > Q;
  Q.push(make_pair(0, 0));
  for (int i = 0; i < (n); ++i)
    if (i) {
      if (A[i].first == A[Q.top().first].first) {
        Q.push(make_pair(i, Q.top().second));
        continue;
      }
      while (!Q.empty() &&
             better(A[i].first, A[Q.top().first].first, Q.top().second)) {
        Q.pop();
      }
      if (Q.empty())
        Q.push(make_pair(i, 0));
      else
        Q.push(make_pair(i, get(A[i].first, A[Q.top().first].first)));
    }
  vector<int> wyn;
  while (!Q.empty()) {
    wyn.push_back(Q.top().first);
    Q.pop();
  }
  for (typeof((wyn).begin()) it = (wyn).begin(); it != (wyn).end(); ++it)
    *it = A[*it].second;
  sort((wyn).begin(), (wyn).end());
  for (typeof((wyn).begin()) it = (wyn).begin(); it != (wyn).end(); ++it)
    printf("%d ", *it + 1);
  puts("");
}
int main() {
  int t = 1;
  for (int i = 0; i < (t); ++i) solve();
  return 0;
}
