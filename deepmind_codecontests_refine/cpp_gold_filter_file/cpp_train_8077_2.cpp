#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long a, b;
  cin >> a >> b;
  int maxa = sqrt(a);
  int maxb = maxa * (maxa + 1);
  if (b >= maxb)
    cout << "Vladik";
  else
    cout << "Valera";
}
