#include <bits/stdc++.h>
using namespace std;
const int Maxn = 300 * 1000 + 5;
int n, arr[Maxn];
long long ans[Maxn];
vector<pair<pair<int, int>, pair<int, int> > > vec;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int p, a, b;
  scanf("%d", &p);
  for (int i = 0; i < p; i++) {
    scanf("%d%d", &a, &b);
    a--;
    vec.push_back(make_pair(make_pair(a % b, b), make_pair(a, i)));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    int j = i;
    while (j < (int)vec.size() && vec[i].first == vec[j].first) j++;
    j--;
    b = vec[i].first.second;
    int s = (n / b) * b + vec[i].first.first, jp = j;
    if (s >= n) s -= b;
    long long sum = 0;
    for (int k = s; k >= 0; k -= b) {
      sum += arr[k];
      while (j >= i && k == vec[j].second.first) {
        ans[vec[j].second.second] = sum;
        j--;
      }
    }
    i = jp;
  }
  for (int i = 0; i < p; i++) printf("%I64d\n", ans[i]);
  return 0;
}
