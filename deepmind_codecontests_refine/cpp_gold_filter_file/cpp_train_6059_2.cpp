#include <bits/stdc++.h>
using namespace std;
int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};
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
int const lmt = 1e5 + 5;
long long a[lmt], b[lmt];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  map<long long, int> fre;
  set<long long> st;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    fre[a[i]]++;
  }
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long ans = 0;
  for (long long i = 0; i < n; i++)
    if (fre[a[i]] > 1) ans += b[i], st.insert(a[i]);
  for (long long i = 0; i < n; i++) {
    if (!(st.find(a[i]) != st.end())) {
      for (long long x : st) {
        if ((x | a[i]) == x) {
          ans += b[i];
          break;
        }
      }
    }
  }
  cout << ans << "\n";
}
