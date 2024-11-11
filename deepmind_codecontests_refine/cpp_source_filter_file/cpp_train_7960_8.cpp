#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
bool cmpManh(const std::pair<long long, long long>& l,
             const std::pair<long long, long long>& r) {
  return ((llabs(l.first) + llabs(l.second)) <
          (llabs(r.first) + llabs(r.second)));
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main(void) {
  int n;
  scanf("%d", &n);
  string str;
  cin >> str;
  string ans[10], anss = "!";
  ans[0] = "!";
  ans[1] = "!";
  ans[2] = "2";
  ans[3] = "3";
  ans[4] = "322";
  ans[5] = "5";
  ans[6] = "53";
  ans[7] = "7";
  ans[8] = "7222";
  ans[9] = "9";
  for (int i = 0; i < n; ++i) {
    anss += ans[str[i] - '0'];
  }
  vector<int> q;
  for (int i = 1; i < anss.size(); ++i) {
    if (anss[i] != '!') q.push_back(anss[i] - '0');
  }
  sort(q.begin(), q.end());
  for (int i = q.size() - 1; i > -1; --i) {
    cout << q[i];
  }
  cout << '\n';
  return (0);
}
