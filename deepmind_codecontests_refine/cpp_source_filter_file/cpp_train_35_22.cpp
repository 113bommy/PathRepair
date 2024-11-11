#include <bits/stdc++.h>
using namespace std;
bool is_valid(string s) {
  int part = 0;
  string ans = "";
  bool ok = true;
  int day = 0;
  int month = 0;
  int year = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-') {
      part++;
      int num = stoi(ans);
      ans = "";
      if (part == 1)
        day = num;
      else if (part == 2)
        month = num;
    } else
      ans += s[i];
  }
  year = stoi(ans);
  if (year > 2015 && year < 2013) return false;
  if (month == 0 || month > 12) return false;
  int arr[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  month--;
  if (day == 0 || day > arr[month]) return false;
  return true;
}
int main() {
  map<string, int> m;
  string s;
  cin >> s;
  string temp = "dd-mm-yyyy";
  int n = s.size();
  for (int i = 0; i < n; i++) {
    int length = n - i;
    if (length < 10) break;
    int ptr = i;
    bool ok = true;
    for (int j = 0; j < temp.size(); j++, ptr++) {
      if (temp[j] == 'd' || temp[j] == 'm' || temp[j] == 'y') {
        if (s[ptr] >= '0' && s[ptr] <= '9')
          continue;
        else {
          ok = false;
          break;
        }
      } else {
        if (s[ptr] != '-') {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      m[s.substr(i, 10)]++;
    }
  }
  int max_num = 0;
  string ans = "";
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second == 0) continue;
    if (is_valid(it->first)) {
      if (it->second > max_num) {
        max_num = it->second;
        ans = it->first;
      }
    }
  }
  cout << ans;
}
