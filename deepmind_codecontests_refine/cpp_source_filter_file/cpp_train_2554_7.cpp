#include <bits/stdc++.h>
int main() {
  long n, k;
  std::vector<long> a;
  std::vector<std::pair<int, long long> > mins, maxs;
  long long int sum = 0;
  bool equalizable = false;
  scanf("%ld %ld", &n, &k);
  for (int i = 0; i < n; ++i) {
    long num;
    scanf("%ld", &num);
    a.push_back(num);
    sum += num;
  }
  equalizable = (sum % n == 0);
  std::sort(a.begin(), a.end());
  long long total = 0;
  long first = 0;
  long cur = 0;
  do {
    do {
      cur++;
      if (cur == n) break;
    } while (a[cur] == a[first]);
    cur--;
    if (cur == n - 1) break;
    total += (cur + 1) * (a[cur + 1] - a[cur]);
    mins.push_back(std::make_pair(cur, total));
    first = cur + 1;
  } while ((a[first] != a[n - 1]) && (total < k));
  total = 0;
  first = n - 1;
  cur = n - 1;
  do {
    do {
      cur--;
      if (cur == -1) break;
    } while (a[cur] == a[first]);
    cur++;
    if (cur == 0) break;
    total += (n - cur) * (a[cur] - a[cur - 1]);
    maxs.push_back(std::make_pair(cur, total));
    first = cur - 1;
  } while ((a[first] != a[0]) && (total < k));
  if (mins.empty()) {
    printf("0");
    return 0;
  }
  if (maxs.empty()) {
    printf("0");
    return 0;
  }
  int start_min = (mins.empty()) ? -1 : mins[mins.size() - 1].first;
  int start_max = (maxs.empty()) ? n : maxs[maxs.size() - 1].first;
  if (start_min < start_max) {
    {
      long prev_min, minn, prev_max, maxx;
      if (start_min == -1) {
      } else {
        prev_min = (a[mins[mins.size() - 1].first] == a[0])
                       ? 0
                       : mins[mins.size() - 2].second;
        minn = a[mins[mins.size() - 1].first] +
               (k - prev_min) / (mins[mins.size() - 1].first + 1);
      }
      if (start_max == -1) {
      } else {
        prev_max = (a[maxs[maxs.size() - 1].first] == a[n - 1])
                       ? 0
                       : maxs[maxs.size() - 2].second;
        maxx = a[maxs[maxs.size() - 1].first] -
               (k - prev_max) / (n - maxs[maxs.size() - 1].first);
      }
      if (minn <= maxx) {
        printf("%ld", maxx - minn);
      } else {
        if (equalizable)
          printf("0");
        else
          printf("1");
      }
    }
  } else {
    if (equalizable)
      printf("0");
    else
      printf("1");
  }
  return 0;
}
