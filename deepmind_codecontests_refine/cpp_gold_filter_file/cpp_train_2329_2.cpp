#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt", ios::in);
ofstream fout("output.txt", ios::out);
int main() {
  char s[1000010];
  char st[1000010];
  cin >> (s + 1);
  int k = 1, i;
  for (i = 1; s[i]; i++) {
    if ((k - 1) >= 1) {
      if (s[i] == 'y' && st[k - 1] == 'x')
        k--;
      else if (s[i] == 'x' && st[k - 1] == 'y')
        k--;
      else
        st[k++] = s[i];
    } else
      st[k++] = s[i];
  }
  for (i = 1; i <= k - 1; i++) {
    cout << st[i];
  }
  cout << endl;
  return 0;
}
