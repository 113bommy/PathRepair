#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int oddd_a[100009], oddd_b[100009], even_a[100009], even_b[100009];
  memset(oddd_a, -1, sizeof(oddd_a));
  memset(oddd_b, -1, sizeof(oddd_b));
  memset(even_a, -1, sizeof(even_a));
  memset(even_b, -1, sizeof(even_b));
  oddd_a[0] = 0;
  oddd_b[0] = 0;
  even_a[0] = 0;
  even_b[0] = 0;
  long long odd = 0, even = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if ((i + 1) % 2 == 0) {
      if (s[i] == 'a')
        even_a[i + 1] = even_a[i] + 1;
      else
        even_b[i + 1] = even_b[i] + 1;
    } else {
      if (s[i] == 'a')
        oddd_a[i + 1] = oddd_a[i] + 1;
      else
        oddd_b[i + 1] = oddd_b[i] + 1;
    }
    if (oddd_a[i + 1] == -1) oddd_a[i + 1] = oddd_a[i];
    if (even_a[i + 1] == -1) even_a[i + 1] = even_a[i];
    if (oddd_b[i + 1] == -1) oddd_b[i + 1] = oddd_b[i];
    if (even_b[i + 1] == -1) even_b[i + 1] = even_b[i];
  }
  for (int i = 1; i <= (int)s.size(); i++) {
    if (i % 2 == 1) {
      if (s[i - 1] == 'a') {
        odd += oddd_a[i];
        even += even_a[i];
      } else {
        odd += oddd_b[i];
        even += even_b[i];
      }
    } else {
      if (s[i - 1] == 'a') {
        odd += even_a[i];
        even += oddd_a[i];
      } else {
        odd += even_b[i];
        even += oddd_b[i];
      }
    }
  }
  cout << even << " " << odd << endl;
  return 0;
}
