#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
  err(++it, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Test;
  cin >> Test;
  while (Test--) {
    long long int n;
    cin >> n;
    string a;
    cin >> a;
    vector<long long int> x(n, -1);
    long long int curr = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 'A')
        curr = i;
      else
        x[i] = curr;
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      if ((a[i] == 'P') && (x[i] >= 0)) ans = max(ans, i - x[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
