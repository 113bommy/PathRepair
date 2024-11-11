#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
bool a[1000000];
bool fre[1000000];
int bad = 0;
int m;
int main() {
  cin >> m;
  for (int(i) = (0); i < (m); ++(i)) {
    int c;
    scanf("%d", &c);
    a[c] = true;
  }
  cout << m << "\n";
  for (int(i) = (1); i < (1000000 / 2 + 1); ++(i)) {
    if (!a[i] && !a[1000001 - i]) fre[i] = true;
    if (a[i] && a[1000001 - i]) bad++;
    if (!a[i] && a[1000001 - i]) printf("%d ", i);
    if (a[i] && !a[1000001 - i]) printf("%d ", 1000001 - i);
  }
  for (int(i) = (1); i < (1000000 / 2 + 1); ++(i))
    if (bad && fre[i]) {
      printf("%d ", i);
      printf("%d ", 1000001 - i);
      bad--;
    }
  return 0;
}
