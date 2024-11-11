#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> i, pair<int, int> j) { return i.second < j.second; }
const int MAXN = 100000;
pair<int, int> s[MAXN];
int a[MAXN];
int b[MAXN];
int main() {
  int n;
  cin >> n;
  for (typeof(0) i = (0); i < (n); ++i) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(s, s + n);
  int range = n / 3;
  int remain = n % 3;
  int n1 = range;
  if (remain) {
    n1++;
    remain--;
  }
  for (typeof(0) i = (0); i < (n1); ++i) {
    a[s[i].second] = i;
    b[s[i].second] = s[i].first - i;
  }
  int n2 = range;
  if (remain) {
    n2++;
    remain--;
  }
  for (typeof(n1) i = (n1); i < (n2); ++i) {
    b[s[i].second] = i;
    a[s[i].second] = s[i].first - i;
  }
  for (typeof(n2) i = (n2); i < (n); ++i) {
    b[s[i].second] = n - i - 1;
    a[s[i].second] = s[i].first - (n - i - 1);
  }
  cout << "YES" << endl;
  for (typeof(0) i = (0); i < (n - 1); ++i) cout << a[i] << " ";
  cout << a[n - 1] << endl;
  for (typeof(0) i = (0); i < (n - 1); ++i) cout << b[i] << " ";
  cout << b[n - 1] << endl;
  return 0;
}
