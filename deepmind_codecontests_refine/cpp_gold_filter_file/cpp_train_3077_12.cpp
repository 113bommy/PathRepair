#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  scanf("%lld", &n);
  getchar();
  char a[100007];
  gets(a);
  long long int j;
  long long int ind = 0, se = 0, count = 0;
  for (int i = 0; a[i]; i++) {
    se = 0;
    while (a[i] == ' ') i++;
    j = 0;
    while (a[i + j] && j < n) {
      if (a[i + j] == '.' || a[i + j] == '?' || a[i + j] == '!') {
        se = 1;
        ind = i + j;
      }
      j++;
    }
    if (se != 0) {
      count++;
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
    i = ind + 1;
  }
  cout << count << endl;
  return 0;
}
