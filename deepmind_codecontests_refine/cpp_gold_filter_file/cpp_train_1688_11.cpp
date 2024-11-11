#include <bits/stdc++.h>
using namespace std;
bool check(string s, int* arr) {
  int temp[26] = {0};
  for (int i = 0; i < s.size(); i++) {
    temp[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (temp[i] != arr[i]) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string p, h;
    cin >> p >> h;
    if (h.size() < p.size())
      cout << "NO"
           << "\n";
    else {
      int arr[26] = {0};
      for (int i = 0; i < p.size(); i++) {
        arr[p[i] - 'a']++;
      }
      int flag = 0;
      for (int i = 0; i <= h.size() - p.size(); i++) {
        bool is = check(h.substr(i, p.size()), arr);
        if (is) {
          cout << "YES"
               << "\n";
          flag++;
          break;
        }
      }
      if (flag == 0)
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
