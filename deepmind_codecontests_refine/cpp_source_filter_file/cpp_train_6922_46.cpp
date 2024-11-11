#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, k, m;
  cin >> n1 >> n2 >> k >> m;
  long long int a1[n1];
  long long int a2[n2];
  for (int i = 0; i < n1; i++) {
    cin >> a1[i];
  }
  for (int i = 0; i < n2; i++) {
    cin >> a2[i];
  }
  if (a1[k - 1] < a2[0])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
