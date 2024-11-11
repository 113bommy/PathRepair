#include <bits/stdc++.h>
using namespace std;
long long n, ar[100005], er[50], br[50];
map<long long, long long> mr;
vector<long long> ans;
long long func(long long idx, long long rows, long long tot, long long ext,
               long long con);
int main() {
  long long t = 1;
  mr[t] = 0;
  for (int i = 1; i < 41; i++) {
    t *= 2;
    mr[t] = i;
  }
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ar[i]);
    if (mr.find(ar[i]) != mr.end()) {
      br[mr[ar[i]]]++;
    } else {
      for (int j = 1; j < 50; j++) {
        if ((1ll << (j - 1)) < ar[i] && ar[i] < (1ll << j)) {
          er[j]++;
        }
      }
    }
  }
  for (int i = 1; i < br[0] + 1; i++) {
    if (func(1, i, i, br[0] - i, 0)) ans.push_back(i);
  }
  if (ans.size() == 0)
    printf("-1");
  else
    for (int i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
}
long long func(long long idx, long long rows, long long tot, long long ext,
               long long con) {
  if (tot == n) return 1;
  if (idx == 40) return 0;
  long long left = er[idx] + ext - con;
  if (br[idx] < rows) {
    long long places = rows - br[idx];
    tot += br[idx];
    if (places >= left) {
      places -= left;
      tot += left;
      con += left;
      left = 0;
    } else if (left > places) {
      left -= places;
      tot += places;
      con += places;
      places = 0;
    }
    return func(idx + 1, br[idx], tot, ext + er[idx], con);
  } else {
    return func(idx + 1, rows, tot + rows, ext + er[idx] + (br[idx] - rows),
                con);
  }
}
