#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265358979323846;
const int MAX = 1e9;
const int rx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const int ry[8] = {0, -1, 1, 0, -1, 1, 1, -1};
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long n, x, ans, h, as;
vector<long long> a[5], el;
string s;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> s >> x;
    if (s == "00")
      a[1].push_back(x);
    else if (s == "10")
      a[2].push_back(x);
    else if (s == "01")
      a[3].push_back(x);
    else
      a[4].push_back(x), ans += x, h++, as++;
  }
  sort(a[1].begin(), a[1].end(), greater<long long>());
  sort(a[2].begin(), a[2].end(), greater<long long>());
  sort(a[3].begin(), a[3].end(), greater<long long>());
  if (min(a[2].size(), a[3].size()) > 0)
    for (long long i = 0; i < min(a[2].size(), a[3].size()); i++) {
      ans += a[2][i];
      ans += a[3][i];
      h++;
      as += 2;
    }
  if (a[2].size() < a[3].size()) {
    for (long long i = a[2].size(); i < a[3].size(); i++) el.push_back(a[3][i]);
  } else if (a[3].size() < a[2].size()) {
    for (long long i = a[3].size(); i < a[2].size(); i++) el.push_back(a[2][i]);
  }
  if (!a[1].empty())
    for (long long i = 0; i < a[1].size(); i++) {
      el.push_back(a[1][i]);
    }
  sort(el.begin(), el.end(), greater<long long>());
  long long hh = h;
  if (!el.empty())
    for (long long i = 0; i < el.size() && as < hh * 2; i++, as++) {
      ans += el[i];
    }
  cout << ans;
  return 0;
}
