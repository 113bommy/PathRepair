#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char miao[10] = "miao.";
char lala[10] = "lala.";
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    bool ok1 = 1, ok2 = 1;
    int len = s.length();
    for (int j = 0, k = 0; k < 5; j++, k++)
      if (s[j] != miao[k]) ok1 = 0;
    for (int j = max(len - 5, 0), k = 0; k < 5; j++, k++)
      if (s[j] != lala[k]) ok2 = 0;
    if (!(ok1 ^ ok2))
      cout << "OMG>.< I don't know!" << endl;
    else if (ok1)
      cout << "Rainbow's" << endl;
    else
      cout << "Freda's" << endl;
  }
  return 0;
}
