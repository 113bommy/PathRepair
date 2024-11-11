#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
string to_string1(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
long long to_integer(string s) {
  stringstream ss(s);
  long long x;
  ss >> x;
  return x;
}
void solve() { return; }
int main() {
  vector<int> v(11);
  vector<double> ans(11);
  for (int i = 0; i < 11; i++) {
    cin >> v[i];
    double a = sqrt(abs(v[i]));
    double b = pow(v[i], 3) * 5;
    ans[i] = (a + b);
  }
  for (int i = 10; i >= 0; i--) {
    cout << "f(" << i << ") = ";
    if (ans[i] > 400) {
      cout << "MAGNA NIMIS!"
           << "\n";
    } else {
      printf("%.2f", ans[i]);
      cout << "\n";
    }
  }
  return 0;
}
