#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool comps(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  long long int n;
  long long int k;
  cin >> n;
  long long int f = 0, s = 0;
  long long int l, lll = -1;
  vector<long long int> a;
  vector<long long int> b;
  while (n--) {
    cin >> k;
    if (k > 0) {
      l = 0;
      f += k;
      a.push_back(k);
    } else
      s += (-1) * k, l = 1, b.push_back((-1) * k);
  }
  for (int i = 0; i < min((a).size(), (b).size()); i++) {
    if (a[i] > b[i]) lll = 0;
    if (a[i] < b[i]) lll = 1;
    if (l != -1) break;
  }
  if (lll = -1) {
    if ((a).size() > (b).size())
      lll = 0;
    else if ((b).size() > (a).size())
      lll = 1;
  }
  if (f > s)
    cout << "first";
  else if (s > f)
    cout << "second";
  else {
    if (lll == 0)
      cout << "first";
    else if (lll == 1)
      cout << "second";
    else {
      if (l)
        cout << "second";
      else
        cout << "first";
    }
  }
  return 0;
}
