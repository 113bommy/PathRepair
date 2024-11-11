#include <bits/stdc++.h>
using namespace std;
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
  cerr << '\n';
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
const int N = 1e5 + 5, mod = 1e9 + 7, mod2 = 998244353, MAXN = 100000 + 29;
void files() {}
bitset<N> bits[26];
int countt(bitset<N> &a, int l) {
  int shift = N - l;
  return (a << shift).count();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  files();
  string s;
  cin >> s;
  int q;
  cin >> q;
  for (int i = 0; i < ((int)((s).size())); ++i) {
    bits[s[i] - 'a'].set(i);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      cin >> i;
      i--;
      char c;
      cin >> c;
      bits[s[i] - 'a'].reset(i);
      s[i] = c;
      bits[s[i] - 'a'].set(i);
    } else {
      int l, r;
      cin >> l >> r;
      string sub;
      cin >> sub;
      bitset<N> ans;
      ans.set();
      for (int i = 0; i < ((int)((sub).size())); ++i) {
        ans &= (bits[sub[i] - 'a'] >> i);
      }
      int shift = N - r + ((int)((sub).size())) - 1;
      int res = (ans << shift).count();
      shift = N - l + 1;
      res -= (ans << shift).count();
      cout << res << '\n';
    }
  }
}
