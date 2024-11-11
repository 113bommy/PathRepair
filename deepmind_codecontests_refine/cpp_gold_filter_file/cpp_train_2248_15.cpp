#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool isok(int sum, int k) {
  int cnt = 0, x = 0;
  int i;
  for (i = 0; i < v.size(); i++) {
    if (v[i] > sum) return false;
    if (x + v[i] <= sum) {
      x += v[i];
    } else {
      x = v[i];
      cnt++;
    }
  }
  cnt++;
  if (cnt <= k)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, x;
  string a, s;
  cin >> n;
  getline(cin, a);
  getline(cin, s);
  x = -1;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || s[i] == '-') {
      v.push_back(i - x);
      x = i;
    }
  }
  v.push_back(i - x - 1);
  int l, r, mid;
  l = 1;
  r = 1001000;
  while (l < r - 1) {
    mid = l + (r - l) / 2;
    if (isok(mid, n)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (isok(l, n)) {
    cout << l << endl;
  } else if (isok(r, n)) {
    cout << r << endl;
  }
  return 0;
}
