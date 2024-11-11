#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  getline(cin, s);
  char v[] = {'a', 'e', 'i', 'u', 'y', 'o', 'A', 'E', 'O', 'I', 'Y', 'U'};
  int l = 0, flag = 0;
  for (int i = 0; s[i] != 0; i++) l++;
  for (int i = l; i > 0; i--) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      flag = 1;
      for (int j = 0; j < 12; j++)
        if (s[i] == v[j]) {
          cout << "YES" << endl;
          i = 0;
          flag = 123;
          break;
        }
    }
    if (flag == 1) {
      cout << "NO" << endl;
      break;
    }
  }
  return 0;
}
