#include <bits/stdc++.h>
using namespace std;
vector<string> ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int len = r - l + 1;
  vector<string> res(len * (len + 1) / 2);
  for (int i = 0; i < len * (len + 1) / 2; ++i) {
    cin >> res[i];
    sort(res[i].begin(), res[i].end());
  }
  return res;
}
char diff(string &a, string &b) {
  map<char, int> cnt;
  for (auto it : a) {
    --cnt[it];
  }
  for (auto it : b) {
    ++cnt[it];
  }
  for (auto it : cnt) {
    if (it.second == 1) {
      return it.first;
    }
  }
  return '~';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "! " << ask(1, 1)[0] << endl;
    return 0;
  }
  vector<string> a = ask(1, n);
  vector<string> b = ask(2, n);
  map<string, int> cnt;
  for (auto it : a) {
    ++cnt[it];
  }
  for (auto it : b) {
    --cnt[it];
  }
  vector<string> prefs(n);
  for (auto it : cnt) {
    if (it.second == 1) {
      prefs[(int)it.first.length() - 1] = it.first;
    }
  }
  cout << "! " << prefs[0];
  for (int i = 1; i < (int)prefs.size(); ++i) {
    cout << diff(prefs[i - 1], prefs[i]);
  }
  cout << endl;
  return 0;
}
