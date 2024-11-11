#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MAXN = 2000005;
const int MAXINT = 1073741823;
long long int a[MAXN];
pair<pair<int, int>, int> queries[MAXN];
int countof[MAXN];
long long int answer_of[MAXN];
long long int answer, root = 400;
void increase(long long int s) {
  long long int number = countof[s];
  answer += (2 * number + 1) * s;
  countof[s]++;
  return;
}
void decrease(long long int s) {
  long long int number = countof[s];
  answer -= (2 * number - 1) * s;
  countof[s]--;
  return;
}
bool comparison(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  if (x.first.first / root != y.first.first / root)
    return x.first.first < y.first.first;
  return x.first.second < y.first.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, t, from, to, pre_from, pre_to;
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < t; i++) {
    cin >> from >> to;
    from--;
    to--;
    queries[i] = make_pair(make_pair(from, to), i);
  }
  sort(queries, queries + t, comparison);
  for (int i = 0; i < t; i++) {
    if (i > 0) {
      while (queries[i].first.first < pre_from) {
        pre_from--;
        increase(a[pre_from]);
      }
      while (queries[i].first.second > pre_to) {
        pre_to++;
        increase(a[pre_to]);
      }
      while (queries[i].first.first > pre_from) {
        decrease(a[pre_from]);
        pre_from++;
      }
      while (queries[i].first.second < pre_to) {
        decrease(a[pre_to]);
        pre_to--;
      }
    } else
      for (int j = queries[i].first.first; j <= queries[i].first.second; j++)
        increase(a[j]);
    pre_from = queries[i].first.first;
    pre_to = queries[i].first.second;
    answer_of[queries[i].second] = answer;
  }
  for (int i = 0; i < t; i++) cout << answer_of[i] << '\n';
  return 0;
}
