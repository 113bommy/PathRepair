#include <bits/stdc++.h>
using namespace std;
void boost() { ios_base::sync_with_stdio(0); }
long long a, sum;
int x[100001];
int z[100001];
int main() {
  boost();
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> x[i];
    sum = sum + x[i];
  }
  for (int i = 0; i < a; i++) {
    cin >> z[i];
  }
  sort(z, z + a);
  if (sum <= z[a - 1] + z[a - 2]) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
