#include <bits/stdc++.h>
using namespace std;
long long int a;
int main() {
  cin >> a;
  cout << a / 2 << endl;
  for (int i = 0; i < a / 2 - 1; i++) cout << 2 << " ";
  if (a % 2)
    cout << 3 << endl;
  else
    cout << 2 << endl;
}
