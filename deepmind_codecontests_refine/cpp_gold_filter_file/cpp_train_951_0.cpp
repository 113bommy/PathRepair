#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  vector<int>::iterator it;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  vector<int> seq;
  seq.push_back(-1);
  string ans;
  while (1) {
    if (v.back() <= seq.back() && v[0] <= seq.back()) break;
    if (v.empty()) break;
    if (v.size() == 1 && v[0] > seq.back()) {
      ans += 'R';
      break;
    }
    if (v.back() < v[0] && seq.back() < v.back()) {
      seq.push_back(v.back());
      ans += 'R';
      it = v.end();
      it--;
      v.erase(it);
    } else if (v[0] < v.back() && seq.back() < v[0]) {
      seq.push_back(v[0]);
      ans += 'L';
      v.erase(v.begin());
    } else if (v[0] == v.back()) {
      int cnt_lft = 0, cnt_rit = 0;
      for (int i = 1; v[i] > v[i - 1]; i++) cnt_lft++;
      for (int i = v.size() - 2; v[i] > v[i + 1]; i--) cnt_rit++;
      if (cnt_lft > cnt_rit) {
        ans += 'L';
        for (int i = 1; v[i] > v[i - 1]; i++) ans += 'L';
        break;
      } else {
        ans += 'R';
        for (int i = v.size() - 2; v[i] > v[i + 1]; i--) ans += 'R';
        break;
      }
    } else if (v[0] > seq.back()) {
      seq.push_back(v[0]);
      ans += 'L';
      v.erase(v.begin());
    } else if (v.back() > seq.back()) {
      seq.push_back(v.back());
      ans += 'R';
      it = v.end();
      it--;
      v.erase(it);
    }
    if (v.back() <= seq.back() && v[0] <= seq.back()) break;
    if (v.empty()) break;
    if (v.size() == 1 && v[0] > seq.back()) {
      ans += 'R';
      break;
    }
  }
  cout << ans.size() << endl << ans << endl;
}
