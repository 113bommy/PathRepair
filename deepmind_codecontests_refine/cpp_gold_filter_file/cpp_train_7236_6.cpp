#include <bits/stdc++.h>
using namespace std;
long long int x[10], y[10];
bool is(int i, int j) { return x[i] == x[j] || y[i] == y[j]; }
int v[] = {0, 1, 2};
pair<long long int, long long int> b[3];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 3; i++) cin >> b[i].first >> b[i].second;
  sort(b, b + 3);
  int ans1 = 0;
  int ans2 = 0;
  if (b[0].first == b[1].first) {
    if (b[2].first == b[1].first)
      ans1 = 1;
    else if (b[2].second >= b[1].second || b[2].second <= b[0].second)
      ans1 = 2;
    else
      ans1 = 3;
  } else if (b[0].second == b[1].second) {
    if (b[2].second == b[1].second)
      ans1 = 1;
    else if (b[2].first >= b[1].first || b[2].first <= b[0].first)
      ans1 = 2;
    else
      ans1 = 2;
  } else
    ans1 = 3;
  reverse(b, b + 3);
  if (b[0].first == b[1].first) {
    if (b[2].first == b[1].first)
      ans2 = 1;
    else if (b[2].second <= b[1].second || b[2].second >= b[0].second)
      ans2 = 2;
    else
      ans2 = 3;
  } else if (b[0].second == b[1].second) {
    if (b[2].second == b[1].second)
      ans2 = 1;
    else if (b[2].first <= b[1].first || b[2].first >= b[0].first)
      ans2 = 2;
    else
      ans2 = 2;
  } else
    ans2 = 3;
  for (int i = 0; i < 3; i++) {
    swap(b[i].first, b[i].second);
  }
  int ansf = min(ans1, ans2);
  sort(b, b + 3);
  if (b[0].first == b[1].first) {
    if (b[2].first == b[1].first)
      ans1 = 1;
    else if (b[2].second >= b[1].second || b[2].second <= b[0].second)
      ans1 = 2;
    else
      ans1 = 3;
  } else if (b[0].second == b[1].second) {
    if (b[2].second == b[1].second)
      ans1 = 1;
    else if (b[2].first >= b[1].first || b[2].first <= b[0].first)
      ans1 = 2;
    else
      ans1 = 2;
  } else
    ans1 = 3;
  reverse(b, b + 3);
  if (b[0].first == b[1].first) {
    if (b[2].first == b[1].first)
      ans2 = 1;
    else if (b[2].second <= b[1].second || b[2].second >= b[0].second)
      ans2 = 2;
    else
      ans2 = 3;
  } else if (b[0].second == b[1].second) {
    if (b[2].second == b[1].second)
      ans2 = 1;
    else if (b[2].first <= b[1].first || b[2].first >= b[0].first)
      ans2 = 2;
    else
      ans2 = 2;
  } else
    ans2 = 3;
  cout << min(ansf, min(ans1, ans2));
  return 0;
}
