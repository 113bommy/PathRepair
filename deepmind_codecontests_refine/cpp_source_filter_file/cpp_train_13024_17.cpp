#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  if (n % t == 0)
    cout << t / n;
  else
    cout << t / n + 1;
}
