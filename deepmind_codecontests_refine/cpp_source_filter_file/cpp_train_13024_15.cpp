#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int a = s / n;
  if (s % n) a++;
  cout << n << endl;
  return 0;
}
