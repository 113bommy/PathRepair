#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 2e3 + 5;
const int INF = 200000000;
const double EPS = 1e-6;
string a;
int wton(int l, int r) {
  int num(0);
  int p = r - l + 1;
  while (p) {
    num += ((a[l] - '0') * pow(10, p - 1));
    p--;
    l++;
  }
  return num;
}
void solve() {
  set<int> puk;
  vector<int> num;
  cin >> a;
  int l = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == ',') {
      puk.insert(wton(l, i - 1));
      l = i + 1;
    }
  }
  puk.insert(wton(l, a.size() - 1));
  set<int>::iterator it = puk.begin();
  for (; it != puk.end(); it++) num.push_back(*it);
  cout << num[0];
  for (int i = 1; i < num.size(); i++) {
    if (num[i] - num[i - 1] <= 1 && num[i + 1] - num[i] > 1)
      cout << "-" << num[i];
    else if (i == num.size() - 1 && num[i] - num[i - 1] > 1) {
      cout << "," << num[i];
    } else if (num[i] - num[i - 1] > 1 && num[i + 1] - num[i] <= 1)
      cout << num[i];
    else if (i == num.size() - 1 && num[i] - num[i - 1] <= 1) {
      cout << "-" << num[i];
    } else if (num[i] - num[i - 1] > 1 && num[i + 1] - num[i] > 1)
      cout << "," << num[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
