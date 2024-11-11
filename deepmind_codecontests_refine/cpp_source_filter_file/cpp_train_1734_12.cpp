#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> ans, cur;
void go(vector<int> val, vector<int> ret, int num) {
  if ((int)val.size() == 0) {
    if ((int)ret.size() < (int)ans.size()) ans = ret;
    return;
  }
  if ((int)val.size() == 1 && abs(val[0]) <= 1) {
    ret.push_back(val[0] * num);
    if ((int)ret.size() < (int)ans.size()) ans = ret;
    return;
  }
  if (num >= 19) return;
  int check = 0;
  for (int x : val) {
    if (x % 2 == 1) {
      check = 1;
      break;
    }
  }
  if (!check) {
    for (int i = 0; i < (int)val.size(); i++) val[i] /= 2;
    go(val, ret, num + 1);
    return;
  }
  vector<int> val1, val2;
  for (int i = 0; i < (int)val.size(); i++) {
    if (val[i] % 2 == 0) {
      val1.push_back(val[i] / 2);
      val2.push_back(val[i] / 2);
      continue;
    }
    if (val[i] + 1 != 0) {
      val1.push_back((val[i] + 1) / 2);
    }
    if (val[i] - 1 != 0) {
      val2.push_back((val[i] - 1) / 2);
    }
  }
  val1.erase(unique(val1.begin(), val1.end()), val1.end());
  val2.erase(unique(val2.begin(), val2.end()), val2.end());
  ret.push_back(-num);
  go(val1, ret, num + 1);
  ret.pop_back();
  ret.push_back(num);
  go(val2, ret, num + 1);
}
int pw(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int res = pw(a, b / 2);
  if (b % 2 == 0) return res * res;
  return res * res * a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == 0) continue;
    cur.push_back(x);
  }
  sort(cur.begin(), cur.end());
  cur.erase(unique(cur.begin(), cur.end()), cur.end());
  ans.resize(30);
  go(cur, {}, 1);
  cout << (int)ans.size() << "\n";
  for (int x : ans) {
    if (x < 0)
      cout << -pw(2, -x - 1) << " ";
    else
      cout << pw(2, x - 1) << " ";
  }
}
