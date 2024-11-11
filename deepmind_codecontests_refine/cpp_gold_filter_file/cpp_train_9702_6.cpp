#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
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
  cerr << endl;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  long long t1 = x1, t2 = y1;
  x1 = t1 + t2, y1 = t2 - t1;
  t1 = x2, t2 = y2;
  x2 = t1 + t2;
  y2 = t2 - t1;
  a += a, b += b;
  if (x2 < x1) {
    swap(x1, x2);
    swap(y1, y2);
  }
  x1 = x1 / a + (x1 > 0);
  x2 = x2 / a + (x2 > 0);
  y1 = y1 / b + (y1 > 0);
  y2 = y2 / b + (y2 > 0);
  cout << max(abs(y1 - y2), abs(x2 - x1));
}
