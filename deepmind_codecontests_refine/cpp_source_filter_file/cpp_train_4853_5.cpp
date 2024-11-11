#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<long long> s{0};
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    s.push_back(s.back() + a);
  }
  vector<pair<int, int>> mxl(s.size()), mxr(s.size());
  mxl[0] = {s.front(), 0};
  for (int i = 1; i < s.size(); i++)
    if (s[i] > mxl[i - 1].first)
      mxl[i] = {s[i], i};
    else
      mxl[i] = mxl[i - 1];
  mxr[s.size() - 1] = {s.back(), s.size() - 1};
  for (int i = s.size() - 2; i >= 0; i--)
    if (s[i] > mxr[i + 1].first)
      mxr[i] = {s[i], i};
    else
      mxr[i] = mxr[i + 1];
  long long mx = LLONG_MIN;
  int d1, d2, d3;
  for (int i = 0; i <= n; i++)
    if (mxl[i].first + mxr[i].first - s[i] > mx) {
      mx = mxl[i].first + mxr[i].first - s[i];
      d1 = mxl[i].second, d2 = i, d3 = mxr[i].second;
    }
  printf("%d %d %d\n", d1, d2, d3);
  return 0;
}
