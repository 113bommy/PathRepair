#include <bits/stdc++.h>
using namespace std;
const int maxM = 11;
long long masks[maxM], p[64];
int match[maxM];
vector<long long> ma[6];
int main() {
  for (int i = 0; i < (64); ++i) p[i] = 1LL << i;
  int n, m, res = 0;
  string s;
  cin >> n >> m;
  for (int i = 0; i < (m); ++i) {
    cin >> s;
    masks[i] = 0;
    for (__typeof((s).begin()) j = ((s).begin()); j != (s).end(); ++j)
      masks[i] *= 2, masks[i] += *j - '0';
    cin >> match[i];
  }
  ma[0].push_back(0);
  vector<int> a(n, 0);
  for (int i = (1); i <= (min(5, n)); ++i) {
    a[n - i] = 1;
    do {
      long long v = 0;
      for (__typeof((a).begin()) j = ((a).begin()); j != (a).end(); ++j)
        v *= 2, v += *j;
      ma[i].push_back(v);
    } while (next_permutation((a).begin(), (a).end()));
  }
  for (__typeof((ma[match[0]]).begin()) i = ((ma[match[0]]).begin());
       i != (ma[match[0]]).end(); ++i) {
    long long v = 0;
    for (int j = 0; j < (n); ++j)
      if (*i & p[j])
        v += masks[0] & p[j];
      else if (!(masks[0] & p[j]))
        v += p[j];
    for (int j = (1); j <= (m - 1); ++j)
      if (n - __builtin_popcountll(v ^ masks[j]) != match[j]) goto C;
    res++;
  C:;
  }
  cout << res << endl;
  return 0;
}
