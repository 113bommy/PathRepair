#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9;
pair<int, int> a[maxn];
int b[maxn];
int c[maxn];
vector<pair<int, int> > answer;
bool check(int d) {
  bool flag = 1;
  for (; d > 0; d /= 10) flag = flag && (d % 10 == 7 || d % 10 == 4);
  return flag;
}
int main() {
  int n, pos = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    a[i].first = b[i];
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; pos == -1 && i < n; i++) {
    if (check(a[i].first)) pos = i;
  }
  fprintf(stderr, "pos %d\n", pos);
  if (pos == -1) {
    bool flag = 1;
    for (int i = 1; i < n; i++) flag = flag && b[i - 1] <= b[i];
    printf("%d\n", (int)flag - 1);
    return 0;
  }
  for (int i = 0; i < n; i++) {
    c[a[i].second] = i;
  }
  pos = a[pos].second;
  fprintf(stderr, "pos %d\n", pos);
  for (int i = 0; i < n; i++) {
    if (pos != i) {
      answer.push_back(make_pair(pos, i));
      swap(c[pos], c[i]);
      swap(a[c[pos]].second, a[c[i]].second);
      pos = i;
    }
    if (pos != a[i].second) {
      answer.push_back(make_pair(pos, a[i].second));
      swap(c[i], c[a[i].second]);
      pos = a[i].second;
      swap(a[c[i]].second, a[c[a[i].second]].second);
    }
  }
  printf("%d\n", (int)answer.size());
  for (int i = 0; i < (int)answer.size(); i++)
    printf("%d %d\n", answer[i].first, answer[i].second);
  for (int i = 0; i < (int)answer.size(); i++) {
    assert(check(b[answer[i].first]) || check(b[answer[i].second]));
    swap(b[answer[i].first], b[answer[i].second]);
  }
  for (int i = 0; i < n - 1; i++) assert(b[i] <= b[i + 1]);
  return 0;
}
