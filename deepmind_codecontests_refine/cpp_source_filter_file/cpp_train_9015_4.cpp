#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " , ";
  __f(comma + 1, args...);
}
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 2e7 + 5;
const int inf = 1e9;
const long long INF = 1e18;
int step[N], sum[N];
int len;
string s;
void calc() {
  for (int i = 0; i < N; i++) {
    if (i <= 9) {
      step[i] = 0;
      sum[i] = i;
    } else {
      sum[i] = sum[i / 10] + (i % 10);
      step[i] = step[sum[i]] + 1;
    }
  }
}
void solve(int v, int st, int cnt) {
  if (st == 0) {
    if (cnt < 3) cout << v << "\n";
    return;
  }
  vector<int> dig;
  while (v) dig.push_back(v % 10), v /= 10;
  reverse(dig.begin(), dig.end());
  for (int trial = 1; trial <= 500; trial++) {
    vector<bool> p((int)dig.size() + 1);
    int num = 0, val = 0;
    for (int i = 0; i < dig.size();) {
      int f = rng() % ((2) - (1) + 1) + (1);
      while (f-- && i < len) num = num * 10 + dig[i], i++;
      p[i - 1] = true;
      val += num;
      num = 0;
    }
    if (val < N && step[val] <= st - 1) {
      for (int i = 0; i < dig.size(); i++) {
        cout << dig[i];
        if (p[i] && i != dig.size() - 1) cout << "+";
      }
      cout << "\n";
      solve(val, st - 1, cnt + 1);
      return;
    }
  }
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  calc();
  cin >> len >> s;
  for (int trial = 1; trial <= 500; trial++) {
    int num = 0, val = 0;
    vector<bool> put((int)s.size() + 1);
    for (int i = 0; i < len;) {
      int f = rng() % ((3) - (1) + 1) + (1);
      while (f-- && i < len) num = num * 10 + (s[i] - '0'), i++;
      put[i - 1] = true;
      val += num;
      num = 0;
    }
    if (val < N && step[val] <= 2) {
      for (int i = 0; i < len; i++) {
        cout << s[i];
        if (put[i] && i != len - 1) cout << "+";
      }
      cout << "\n";
      if (step[val] == 0) {
        cout << val << "\n";
        cout << val << "\n";
        goto done;
      }
      solve(val, step[val], 2);
      goto done;
    }
  }
done:
  return 0;
}
