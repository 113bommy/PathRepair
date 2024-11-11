#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long n;
  cin >> n;
  if (n % 2 != 0)
    cout << (n - 1) / 2 << endl;
  else
    cout << (n - 2) / 2 << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solution();
  return 0;
}
