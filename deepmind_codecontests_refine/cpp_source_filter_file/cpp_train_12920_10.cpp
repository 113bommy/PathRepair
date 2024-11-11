#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    int n = s.length();
    int arr[3] = {0};
    for (int i = 0; i < n; i++) {
      if (s[i] >= '0' && s[i] <= '9')
        arr[0]++;
      else if (s[i] >= 'a' && s[i] <= 'z')
        arr[1]++;
      else if (s[i] >= 'A' && s[i] <= 'Z')
        arr[2]++;
    }
    if (arr[0] && arr[1] && arr[2]) {
      cout << s << endl;
      continue;
    }
    if (arr[0] && arr[1]) {
      if (arr[0] > 1) {
        for (int i = 0; i < n; i++) {
          if (s[i] >= '0' && s[i] <= '9') {
            s[i] = 'A';
            break;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'a';
            break;
          }
        }
      }
    } else if (arr[1] && arr[2]) {
      if (arr[1] > 1) {
        for (int i = 0; i < n; i++) {
          if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = '1';
            break;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = '1';
            break;
          }
        }
      }
    } else if (arr[0] && arr[2]) {
      if (arr[0] > 1) {
        for (int i = 0; i < n; i++) {
          if (s[i] >= '0' && s[i] <= '9') {
            s[i] = 'a';
            break;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'a';
            break;
          }
        }
      }
    } else if (arr[0]) {
      s[0] = 'A';
      s[1] = 'a';
    } else if (arr[1]) {
      s[0] = '1';
      s[1] = 'A';
    } else {
      s[0] = '1';
      s[1] = 'a';
    }
    cout << s << endl;
  }
}
