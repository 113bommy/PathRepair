#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long need[N];
vector<long long> dayForType[N];
long long n, m;
long long f(long long days) {
  vector<vector<long long> > typesForDay(days + 1, vector<long long>(m, 0));
  for (long long type = 0; type < n; type++) {
    long long lastDayInd = upper_bound((dayForType[type]).begin(),
                                       (dayForType[type]).end(), days) -
                           dayForType[type].begin() - 1;
    if (lastDayInd >= 0) {
      long long lastDay = dayForType[type][lastDayInd];
      typesForDay[lastDay].push_back(type);
    }
  }
  vector<long long> remain(n);
  for (long long i = 0; i < n; i++) {
    remain[i] = need[i];
  }
  long long money = 0;
  for (long long day = 1; day < days + 1; day++) {
    money++;
    for (auto type : typesForDay[day]) {
      long long willTakeOnDiscount = min(money, remain[type]);
      remain[type] -= willTakeOnDiscount;
      money -= willTakeOnDiscount;
    }
  }
  for (long long i = 0; i < n; i++) {
    money -= remain[i] * 2;
  }
  return money >= 0;
}
long long bs(long long l, long long r) {
  if (l == r) {
    return l;
  }
  long long m = (l + r) / 2;
  if (f(m)) {
    return bs(l, m);
  } else {
    return bs(m + 1, r);
  }
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> need[i];
  }
  for (long long i = 0; i < m; i++) {
    long long d, type;
    cin >> d >> type;
    type--;
    dayForType[type].push_back(d);
  }
  for (long long type = 0; type < n; type++) {
    sort((dayForType[type]).begin(), (dayForType[type]).end());
  }
  long long days = bs(1, 4e3);
  cout << days;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  while (tests--) {
    solve();
    cout << "\n";
  }
  return 0;
}
