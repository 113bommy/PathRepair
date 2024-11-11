#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> mouses[300005];
char str[1000];
long long a, b, c, m;
int main() {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
  for (long long(i) = (0); i <= (long long)(m - 1); (i)++) {
    scanf("%lld%s", &mouses[i].first, str);
    string temp(str);
    if (temp == "USB")
      mouses[i].second = 1;
    else
      mouses[i].second = 2;
  }
  sort(mouses, mouses + m);
  pair<long long, long long> ans;
  for (pair<long long, long long> x : mouses) {
    if ((b || c) && x.second == 2)
      ++ans.first, ans.second += x.first, c ? --c : --b;
    else if ((a || b) && x.second == 1)
      ++ans.first, ans.second += x.first, a ? --a : --b;
  }
  printf("%lld %lld\n", ans.first, ans.second);
}
