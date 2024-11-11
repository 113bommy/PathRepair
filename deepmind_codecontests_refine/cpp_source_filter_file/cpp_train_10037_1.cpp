#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[200001], out[200001];
  int n, j = 0;
  cin >> ch;
  n = strlen(ch);
  for (int i = 0; i < n; ++i) {
    if (j >= 2 && ch[i] == out[i - 1] && ch[i] == out[j - 2]) continue;
    if (j - 3 >= 0 && ch[i] == out[j - 1] && out[j - 2] == out[j - 3]) continue;
    out[j] = ch[i];
    j++;
  }
  out[j] = '\0';
  cout << out << endl;
}
