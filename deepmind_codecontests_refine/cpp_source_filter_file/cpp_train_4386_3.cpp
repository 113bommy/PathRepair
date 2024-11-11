#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
long long power(long long x, long long y) {
  long long v = 1;
  while (y > 0) {
    if (y & 1) v = v * x;
    y = y >> 1;
    x = x * x;
  }
  return v;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << "\n";
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream second;
  second << H;
  cerr << args[idx] << " = " << second.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  init();
  long long test = 1;
  while (test--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    int position = n - 1;
    for (int i = 1; i < n - 1; i++) {
      if (s[i + 1] < s[i]) {
        position = i;
        break;
      }
    }
    string ans = s.substr(0, position) + s.substr(position + 1);
    cout << ans << "\n";
  }
  return 0;
}
