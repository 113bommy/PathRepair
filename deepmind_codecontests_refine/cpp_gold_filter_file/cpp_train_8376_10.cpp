#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 7;
const long long INF = 1e17;
int n;
string orig = "0";
string solve_min(int digits, int sum) {
  string s(digits, '0');
  for (int i = s.length() - 1; i >= 0 && sum > 0; i--) {
    s[i] = (min(9, sum) + '0');
    sum -= min(9, sum);
  }
  return s;
}
pair<string, bool> solve_comp(int ind, int sum) {
  if (ind == orig.length()) return {"", false};
  if ((orig.length() - ind) * 9 < sum) return {"", false};
  pair<string, bool> p = solve_comp(ind + 1, sum - (orig[ind] - '0'));
  if (p.second)
    return {orig.substr(ind, 1) + p.first, true};
  else {
    int rem_digits = orig.length() - ind - 1;
    int cur_val = orig[ind] - '0';
    if (rem_digits * 9 >= sum - (cur_val + 1)) {
      cur_val++;
    } else {
      cur_val = sum - rem_digits * 9;
    }
    if (cur_val > sum || cur_val >= 10) return {"", false};
    return {(char)(cur_val + '0') + solve_min(rem_digits, sum - cur_val), true};
  }
}
string solve(int sum) {
  int digits = (sum - 1) / 9 + 1;
  if (digits > orig.length()) {
    return solve_min(digits, sum);
  } else {
    if (orig == string(orig.length(), '9')) {
      return "1" + solve_min(orig.length(), sum - 1);
    } else {
      pair<string, bool> p = solve_comp(0, sum);
      if (p.second)
        return p.first;
      else
        return "1" + solve_min(orig.length(), sum - 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    string cur = solve(s);
    cout << cur << endl;
    orig = cur;
  }
  return 0;
}
