#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;
int n, m;
pair<int, int> s[MAX];
pair<long long, long long> ans;
void update(long long a, long long b) {
  if (b <= 0) return;
  if (a > ans.first) {
    ans.first = a;
    ans.second = b;
  } else if (a == ans.first)
    ans.second += b;
}
void work1() {
  int i, mi = n, mm = 0;
  long long num = 0;
  for ((i) = (1); (i) <= (m); ++(i))
    if (s[i].first == 0) {
      ++num;
      mi = min(mi, s[i].second);
      mm = max(mm, s[i].second);
    }
  long long num_mi = 0, num_mm = 0;
  for ((i) = (1); (i) <= (m); ++(i)) {
    if (s[i].first == 0 && s[i].second == mi) ++num_mi;
    if (s[i].first == 0 && s[i].second == mm) ++num_mm;
  }
  if (mm == mi) {
    update(0, num * (num - 1) * (num - 2) / 6);
    return;
  }
  num -= num_mi;
  num -= num_mm;
  update((mm - mi) * 2, (num_mi - 1) * num_mi / 2 * num_mm +
                            (num_mm - 1) * num_mm / 2 * num_mi +
                            num * num_mi * num_mm);
}
int cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first < b.first;
}
void work2() {
  sort(s + 1, s + m + 1, cmp);
  int i;
  long long num0 = 0;
  for ((i) = (1); (i) <= (m); ++(i))
    if (s[i].first == 0) ++num0;
  int largb = 0, numb = 0, tmp = num0;
  for ((i) = (1); (i) <= (m); ++(i))
    if (s[i].first == 0) {
      --tmp;
      if (largb != s[i].second)
        update(2LL * n + 2 * largb - 2 * s[i].second, (long long)tmp * numb);
    } else if (s[i].second == largb)
      ++numb;
    else if (s[i].second > largb)
      largb = s[i].second, numb = 1;
  int smallb = 0;
  numb = 0;
  tmp = num0;
  for (i = m; i >= 1; --i)
    if (s[i].first == 0) {
      --tmp;
      if (smallb != s[i].second)
        update(2LL * n - 2 * smallb + 2 * s[i].second, (long long)tmp * numb);
    } else if (s[i].second == smallb)
      ++numb;
    else if (s[i].second < smallb)
      smallb = s[i].second, numb = 1;
  map<int, int> hash;
  for ((i) = (1); (i) <= (m); ++(i))
    if (s[i].first == 0) hash[s[i].second]++;
  tmp = 0;
  for ((i) = (1); (i) <= (m); ++(i)) {
    if (s[i].first == 0)
      ++tmp;
    else {
      long long u = hash[s[i].second];
      long long now = (long long)tmp * (num0 - tmp) +
                      (long long)u * (u - 1) / 2 + (tmp - u) * u;
      update(2LL * n, now);
    }
  }
}
void work() {
  work1();
  work2();
}
int main() {
  int i;
  scanf("%d%d", &n, &m);
  for ((i) = (1); (i) <= (m); ++(i)) scanf("%d%d", &s[i].first, &s[i].second);
  work();
  for ((i) = (1); (i) <= (m); ++(i)) s[i].first ^= 1;
  work();
  cout << ans.second << endl;
  return 0;
}
