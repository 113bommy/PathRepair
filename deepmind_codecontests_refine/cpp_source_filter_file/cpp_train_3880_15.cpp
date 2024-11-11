#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> arr(10, 0), a, b, ttt;
  int n = s.length();
  for (int i = 0; i < n; i++) arr[s[i] - '0']++;
  int ans = 0;
  for (int i = 0; i <= arr[0]; i++) {
    int res = i;
    ttt = arr;
    arr[0] -= i;
    int tmp = res;
    for (int j = 1; j <= 9; j++) {
      if (min(arr[j], arr[10 - j]) == 0) continue;
      res = tmp;
      res++;
      a = arr;
      b = arr;
      a[j]--;
      b[10 - j]--;
      for (int k = 0; k <= 9; k++) res += min(a[k], b[9 - k]);
      ans = max(ans, res);
    }
    ans = max(ans, res);
    arr = ttt;
  }
  for (int i = 0; i <= arr[0]; i++) {
    int res = i;
    ttt = arr;
    arr[0] -= i;
    a = arr;
    b = arr;
    int tmp = res;
    for (int j = 1; j <= 9; j++) {
      if (min(arr[j], arr[10 - j]) == 0) continue;
      res = tmp;
      res++;
      a = arr;
      b = arr;
      a[j]--;
      b[10 - j]--;
      for (int k = 0; k <= 9; k++) res += min(a[k], b[9 - k]);
      if (ans == res) {
        string s1, s2;
        for (int k = 0; k < i; k++) {
          s1.push_back('0');
          s2.push_back('0');
        }
        s1.push_back(j + '0');
        s2.push_back(10 - j + '0');
        for (int k = 0; k <= 9; k++) {
          int x = min(a[k], b[9 - k]);
          for (int y = 0; y < x; y++) {
            s1.push_back(k + '0');
            s2.push_back(9 - k + '0');
          }
        }
        vector<int> tmp(10, 0);
        for (int i = 0; i < s1.length(); i++) tmp[s1[i] - '0']++;
        for (int i = 0; i < 10; i++)
          for (int j = 0; j < arr[i] - tmp[i]; j++) s1.push_back(i + '0');
        tmp.assign(10, 0);
        for (int i = 0; i < s2.length(); i++) tmp[s2[i] - '0']++;
        for (int i = 0; i < 10; i++)
          for (int j = 0; j < arr[i] - tmp[i]; j++) s2.push_back(i + '0');
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        cout << s1 << endl << s2 << endl;
        return 0;
      }
    }
    arr = ttt;
  }
  string s1, s2;
  for (int k = 0; k < ans; k++) {
    s1.push_back('0');
    s2.push_back('0');
  }
  vector<int> tmp(10, 0);
  for (int i = 0; i < s1.length(); i++) tmp[s1[i] - '0']++;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < arr[i] - tmp[i]; j++) s1.push_back(i + '0');
  tmp.assign(10, 0);
  for (int i = 0; i < s2.length(); i++) tmp[s2[i] - '0']++;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < arr[i] - tmp[i]; j++) s2.push_back(i + '0');
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  cout << s1 << endl << s2 << endl;
  return 0;
}
