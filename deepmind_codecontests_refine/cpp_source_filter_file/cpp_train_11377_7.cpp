#include <bits/stdc++.h>
using namespace std;
namespace IO {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (s.size()) {
    setIn(s + ".inp");
    setOut(s + ".out");
  } else {
  }
}
}  // namespace IO
using namespace IO;
namespace Function {
template <typename T1, typename T2>
bool amax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
bool amin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
template <typename T1, typename T2, typename T3>
int position(T1 Begin, T2 End, T3 val, bool type = 0) {
  if (type == 0) {
    return lower_bound(Begin, End, val) - Begin;
  }
  return upper_bound(Begin, End, val) - Begin;
}
template <typename T>
long long sqr(T x) {
  return 1LL * x * x;
}
template <typename T1, typename T2>
long long GCD(T1 a, T2 b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <typename T1, typename T2>
long long LCM(T1 a, T2 b) {
  return 1LL * a / GCD(a, b) * b;
}
}  // namespace Function
using namespace Function;
namespace Output {
char End_Of_Stream = '\n';
void print(int x) { cout << x << End_Of_Stream; }
void print(unsigned int x) { cout << x << End_Of_Stream; }
void print(long unsigned int x) { cout << x << End_Of_Stream; }
void print(long long x) { cout << x << End_Of_Stream; }
void print(unsigned long long x) { cout << x << End_Of_Stream; }
void print(float x) { cout << x << End_Of_Stream; }
void print(double x) { cout << x << End_Of_Stream; }
void print(long double x) { cout << x << End_Of_Stream; }
void print(char x) { cout << x << End_Of_Stream; }
void print(const char *x) { cout << x << End_Of_Stream; }
void print(string x) { cout << x << End_Of_Stream; }
void print(bool x) { cout << x << End_Of_Stream; }
template <typename T1, typename T2>
void print(pair<T1, T2> a) {
  cout << a.first << " " << a.second << End_Of_Stream;
}
template <typename T>
void write(T x) {
  print(x);
}
template <class T, class... Ts>
void write(T t, Ts... ts) {
  write(t);
  write(ts...);
}
template <class T, class... Ts>
void print(T t, Ts... ts) {
  End_Of_Stream = ' ';
  write(t, ts...);
  cout << '\n';
  End_Of_Stream = '\n';
}
template <typename T>
void print(T a, bool type = 0) {
  if (type == 0) {
    End_Of_Stream = ' ';
  }
  for (auto it : a) {
    print(it);
  }
  if (type == 0) {
    cout << '\n';
  }
  End_Of_Stream = '\n';
}
template <class T, class... Ts>
void prine(T t, Ts... ts) {
  print(t, ts...);
  exit(0);
}
}  // namespace Output
using namespace Output;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int INF = 1e9;
const long long INFL = 1e18;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;
long long dp[N];
struct pack {
  int id, num;
};
int main() {
  setIO();
  int n;
  cin >> n;
  int cur = 0;
  vector<pack> t;
  t.push_back({0, 0});
  for (int i = 1; i <= n; i++) {
    char x;
    cin >> x;
    cur += (x == '1');
    while (t.size() > 1 && t.back().num <= cur) {
      t.pop_back();
    }
    if (x == '0') {
      dp[i] = dp[i - 1];
      t.push_back({i - 1, cur});
      cur = 0;
    } else {
      int last = cur;
      dp[i] = 1LL * last * (last + 1) / 2;
      dp[i] += 1LL * (i - last - t.back().id) * last;
      for (int j = t.size() - 1; j > 0; j--) {
        dp[i] += sqr(last);
        dp[i] += 1LL * (t[j].id - t[j].num - t[j - 1].id) * t[j].num;
        dp[i] +=
            1LL * t[j].num * (t[j].num + 1) / 2 - 1LL * last * (last + 1) / 2;
        last = t[j].num;
      }
    }
  }
  print(accumulate(dp + 1, dp + n + 1, 0));
  return 0;
}
