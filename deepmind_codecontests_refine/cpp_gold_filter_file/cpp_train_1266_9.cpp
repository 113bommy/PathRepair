#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  long n = 1;
  for (int i = 1; i < a; i++) n += i * 4;
  cout << n;
  return 0;
}
