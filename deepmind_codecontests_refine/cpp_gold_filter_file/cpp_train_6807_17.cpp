#include <bits/stdc++.h>
void lire_input() { freopen("input.txt", "r", stdin); }
void ecrire_output() { freopen("output.txt", "w", stdout); }
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    for (int i = 0; i < n; i++) {
      printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
      if (i != n)
        printf("%d ", i);
      else
        printf("%d ", 0);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
      if (i != n)
        printf("%d ", (2 * i + 1) % n);
      else
        printf("%d ", i % n);
    }
  } else
    cout << "-1";
  printf("\n");
  return 0;
}
