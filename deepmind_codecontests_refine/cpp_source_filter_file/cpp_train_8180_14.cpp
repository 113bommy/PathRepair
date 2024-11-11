#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n % 4 == 2 || n % 4 == 3) return puts("NO") & 0;
  puts("YES");
  for (int i = 1; i < n; i += 2) {
    for (int j = i + 2; j < n; j++) {
      cout << i << " " << j << endl;
      cout << i + 1 << " " << j + 1 << endl;
      cout << i << " " << j + 1 << endl;
      cout << i + 1 << " " << j << endl;
    }
    if (n % 4) {
      cout << i << " " << n << endl;
      cout << i << " " << i + 1 << endl;
      cout << i + 1 << " " << n << endl;
    } else
      cout << i << " " << i + 1 << endl;
  }
  return 0;
}
