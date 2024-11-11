#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long double eps = 1e-19;
const long double pi = 3.141592653589793238462;
bool isPalindrome(int mid, int lb, int rb, string& str) {
  int l = lb + mid - 1;
  int r = lb + mid + 1;
  int n = rb - lb + 1;
  if (l < lb || r > rb) return false;
  if (str[l] == str[r]) return true;
  return false;
}
int first_step = -1;
int m_save_mass[5001];
string str;
int grundy_2(int len) {
  if (len <= 0) return 0;
  if (m_save_mass[len] != -1) return m_save_mass[len];
  vector<int> m;
  for (int i = 0; i < len; i++) {
    int gfunc = grundy_2(i - 1) ^ grundy_2(len - i - 2);
    m.push_back(gfunc);
  }
  int gnum = 0;
  sort(m.begin(), m.end());
  for (int i = 0; i < m.size(); i++) {
    if (m[i] == gnum) gnum++;
  }
  m_save_mass[len] = gnum;
  return gnum;
}
int solve() {
  int gnum = 0;
  for (int i = 1; i < str.size() - 1; i++) {
    int l = 0;
    while (i < str.size() - 1 && isPalindrome(i, 0, str.size() - 1, str)) {
      l++;
      i++;
    }
    if (l > 0) {
      int gfunc = grundy_2(l);
      gnum ^= gfunc;
    }
  }
  for (int i = 1; i < str.size() - 1; i++) {
    int l = 0;
    while (i < str.size() - 1 && isPalindrome(i, 0, str.size() - 1, str)) {
      l++;
      i++;
    }
    if (l > 0) {
      for (int j = 0; j < l; j++) {
        if (gnum ^ grundy_2(l) ^ grundy_2(j - 1) ^ grundy_2(l - j - 2) == 0) {
          first_step = i - l + j + 1;
          break;
        }
      }
    }
    if (first_step != -1) break;
  }
  return gnum;
}
int main() {
  for (int i = 0; i < 5001; i++) m_save_mass[i] = -1;
  cin >> str;
  if (solve() == 0)
    cout << "Second" << endl;
  else {
    cout << "First" << endl;
    cout << first_step << endl;
  }
  return 0;
}
