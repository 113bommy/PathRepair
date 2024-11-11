#include <bits/stdc++.h>
using namespace std;
int main() {
  char s1[100], s2[100], t1[100], t2[100];
  cin >> s1 >> s2;
  int n;
  cin >> n;
  char s[100], d[100];
  cout << s1 << " " << s2 << endl;
  while (n--) {
    cin >> t1 >> t2;
    int i = 0;
    if (strcmp(s1, t1) == 0) {
      for (i = 0; i < strlen(t2); i++) {
        s1[i] = t2[i];
      }
      s1[i] = NULL;
    } else {
      for (i = 0; i < strlen(t2); i++) {
        s2[i] = t2[i];
      }
      s2[i] = NULL;
    }
    cout << s1 << " " << s2 << endl;
  }
  return 0;
}
