#include <bits/stdc++.h>
using namespace std;
long long int func1(long long int i) {
  long long int m = i;
  return i * (i + 1) * (2 * i + 1) / 6 - (m + m + 2) * i * (i + 1) / 2 +
         (m + m + 1 + m * m) * i;
}
long long int func2(long long int i) { return i + i * i - i * (i + 1) / 2; }
int main() {
  long long int inp, tem, ans = 0, tem2;
  cin >> inp;
  vector<pair<long long int, long long int> > v;
  set<pair<long long int, long long int> > s;
  for (long long int i = 1; func1(i) <= inp; i++) {
    tem = inp - func1(i);
    if (!tem)
      s.insert(make_pair(i, i));
    else {
      tem2 = func2(i);
      if (tem % tem2 == 0) {
        s.insert(make_pair(i, i + tem / tem2));
        s.insert(make_pair(i + tem / tem2, i));
      }
    }
  }
  cout << s.size() << '\n';
  for (auto i = s.begin(); i != s.end(); i++)
    cout << (*i).first << " " << (*i).second << '\n';
  return 0;
}
