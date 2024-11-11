#include <bits/stdc++.h>
using namespace std;
int a, b;
char x[100], y[100];
int main() {
  cin >> x;
  cin >> y;
  a = strlen(x);
  b = strlen(y);
  int k = 0, i;
  for (i = 0; i < b; i++)
    if (x[i] == y[k]) k++;
  cout << k + 1;
}
