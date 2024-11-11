#include <bits/stdc++.h>
using namespace std;
int n, size;
string s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &size);
    cin >> s;
    if (size < 2 || (size < 2 && s[1] < s[0]))
      printf("NO\n");
    else {
      printf("YES\n");
      cout << s[0];
      printf(" ");
      for (int i = 1; i < size; i++) cout << s[i];
      printf("\n");
    }
  }
  return 0;
}
