#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename U>
static inline void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T& x, U y) {
  if (x < y) x = y;
}
vector<string> vec_splitter(string s) {
  for (char& c : s) c = c == ',' ? ' ' : c;
  stringstream ss;
  ss << s;
  vector<string> res;
  for (string z; ss >> z; res.push_back(z))
    ;
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << "): ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
long long int power(long long int b, long long int e) {
  assert(e >= 0);
  if (e == 0) return 1;
  if (e % 2 == 1)
    return b * power(b * b, (e - 1) / 2);
  else
    return power(b * b, e / 2);
}
long long int power(long long int b, long long int e, long long int m) {
  assert(e >= 0);
  if (e == 0) return 1;
  if (e % 2 == 1)
    return b * power(((b % m) * (b % m)) % m, (e - 1) / 2, m) % m;
  else
    return power(((b % m) * (b % m)) % m, e / 2, m) % m;
}
const long double pi = acos(-1);
constexpr int mod = 1e9 + 7;
void swagWaalaFunction() {
  long long int mnW = 10, mnB = -1;
  string s[8];
  for (long long int i = 0; i < (long long int)8; ++i) cin >> s[i];
  for (long long int i = 0; i < (long long int)8; ++i)
    for (long long int j = 0; j < (long long int)8; ++j) {
      if (s[i][j] == 'B') {
        long long int li = i + 1;
        while (li < 8 and s[li][j] == '.') li++;
        if (li == 8) amax(mnB, i + 1);
      }
      if (s[i][j] == 'W') {
        long long int li = i - 1;
        while (li >= 0 and s[li][j] == '.') li--;
        if (li == -1) amin(mnW, i + 1);
      }
    }
  if (mnB == -1)
    cout << "A";
  else if (mnW == 10)
    cout << "B";
  else
    cout << ((mnW <= 9 - mnB) ? "A" : "B");
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int tc = 1;
  for (long long int i = 0; i < (long long int)tc; ++i) {
    swagWaalaFunction();
  }
  return 0;
}
