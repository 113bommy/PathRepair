#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bool start = 0, fin = 0;
    int count = 0;
    int j2 = s.size() - 1;
    for (int j = 0; j <= j2; j++) {
      while (j < s.size() && !start) {
        if (s[j] == '1') {
          start = 1;
          break;
        }
        j++;
      }
      while (j2 > j && !fin) {
        if (s[j2] == '1') {
          fin = 1;
          break;
        }
        j2--;
      }
      if (s[j] == '0') {
        count++;
      }
    }
    cout << count << endl;
  }
}
