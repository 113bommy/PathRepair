#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int i, j;
  char s[100][101];
  int ab[100];
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (i = 0; i < m; i++) {
    cin >> ab[i];
  }
  long long int counter = 0;
  for (i = 0; i < m; i++) {
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (j = 0; j < n; j++) {
      if (s[j][i] == 'A')
        a++;
      else if (s[j][i] == 'B')
        b++;
      else if (s[j][i] == 'C')
        c++;
      else if (s[j][i] == 'D')
        d++;
      else if (s[j][i] == 'E')
        e++;
    }
    int temp = max(a, b);
    temp = max(temp, c);
    temp = max(temp, d);
    temp = max(temp, e);
    counter = counter + (temp * ab[i]);
  }
  cout << counter << endl;
  return 0;
}
