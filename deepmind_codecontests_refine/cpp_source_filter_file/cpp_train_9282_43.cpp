#include <bits/stdc++.h>
using namespace std;
int n, k, m, a;
int main() {
  cin >> n >> m >> k;
  if (m >= n && k >= n)
    cout << "YES";
  else if (m > n && k < n)
    cout << "NO";
  else if (m < n && k < n)
    cout << "NO";
  else if (m < n && k > n)
    cout << "NO";
}
