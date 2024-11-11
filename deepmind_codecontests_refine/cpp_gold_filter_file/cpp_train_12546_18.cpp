#include <bits/stdc++.h>
using namespace std;
vector<long long> vi;
bool cmp(int a, int b) { return a > b; }
int main() {
  int n;
  scanf("%d", &(n));
  long long sum = 0;
  int cnt = 0;
  for (int i = (0); i < (n); ++i) {
    long long k;
    scanf("%lld", &(k));
    if (k % 2) {
      vi.push_back(k);
      cnt++;
    } else
      sum += k;
  }
  sort(vi.begin(), vi.end(), cmp);
  for (int i = (0); i < (cnt / 2 * 2); ++i) {
    sum += vi[i];
  }
  printf("%lld", (sum));
  ;
  return 0;
}
