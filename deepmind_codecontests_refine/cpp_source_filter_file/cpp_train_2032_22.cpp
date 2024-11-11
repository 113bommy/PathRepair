#include <bits/stdc++.h>
using namespace std;
int gcd(int f, int s) {
  if (s == 0)
    return f;
  else
    return gcd(s, f % s);
}
int const N = 1000006;
long long const M = 1020;
long double const ep = .000000000000000001;
long long arr[N], arr1[N];
int main() {
  int n, m;
  scanf("%d", &n);
  long long sum = 0, sum1 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
    sum += arr[i];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld", arr1 + i);
    sum1 += arr1[i];
  }
  if (sum == sum1) {
    printf("0\n0");
    return 0;
  }
  long long best = abs(sum - sum1);
  int ind = -1, ind1 = -1;
  for (int i = 0; i < n; i++) {
    long long temp = sum, temp1 = sum1;
    for (int x = 0; x < m; x++) {
      temp -= arr[i];
      temp += arr1[x];
      temp1 -= arr1[x];
      temp1 += arr[i];
      if (abs(temp - temp1) < best) {
        ind = i + 1, ind1 = x + 1;
        best = abs(temp - temp1);
      }
      temp = sum, temp1 = sum1;
    }
  }
  int indd = -1, indd1 = -1, indd2 = -1, indd21 = -1;
  vector<pair<long long, pair<int, int> > > v, v1;
  for (int i = 0; i < n; i++)
    for (int x = i + 1; x < n; x++)
      v.push_back(make_pair(arr[i] + arr[x], make_pair(i, x)));
  for (int i = 0; i < m; i++)
    for (int x = i + 1; x < m; x++)
      v1.push_back(make_pair(arr1[i] + arr1[x], make_pair(i, x)));
  sort(v1.begin(), v1.end());
  long long want = (sum - sum1) / 2;
  long long test = 1e9;
  long long num = -1;
  for (int i = 0; i < v.size(); i++) {
    int left = 0, right = v1.size() - 1, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      long long curr = v[i].first - v1[mid].first;
      if (test > abs(curr - want)) {
        test = abs(curr - want);
        num = curr;
        indd = v[i].second.first + 1, indd1 = v[i].second.second + 1;
        indd2 = v1[mid].second.first + 1, indd21 = v1[mid].second.second + 1;
      }
      if (curr > want)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  long long s = sum, s1 = sum1;
  s -= num;
  s1 += num;
  if (ind == -1 && indd == -1) {
    printf("%lld\n0", best);
    return 0;
  }
  if (best > abs(s - s1)) {
    printf("%lld\n", abs(s - s1));
    printf("2\n%d %d\n%d %d", indd, indd2, indd1, indd21);
  } else {
    printf("%lld\n", best);
    printf("1\n%d %d", ind, ind1);
  }
  return 0;
}
