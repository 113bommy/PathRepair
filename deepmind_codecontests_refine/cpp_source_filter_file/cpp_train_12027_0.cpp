#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a = 1;
  for (int i = (0); i < (5); ++i) a = (a * 1LL * (n - i));
  cout << a * a / 120LL << endl;
}
