#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  if (s % n) {
    cout << s / n;
  } else
    cout << s / n + 1;
}
