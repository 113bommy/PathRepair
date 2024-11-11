#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
char ar[6] = {'a', 'a', 'b', 'c', 'd'};
int main() {
  scanf("%d", &n);
  for (int i = 1, j = 1; i <= 4 && j <= n; i++, j++) {
    cout << ar[i];
    if (i == 4) i = 0;
  }
  return 0;
}
