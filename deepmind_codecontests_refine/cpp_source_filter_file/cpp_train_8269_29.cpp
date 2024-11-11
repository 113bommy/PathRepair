#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n;
  cin >> n;
  long long m, nn, flag = 0;
  for (int i = 0; i < n; i++) {
    cin >> m >> nn;
    if (m != nn) {
      flag++;
    }
  }
  if (flag == n)
    cout << "Happy Alex\n";
  else
    cout << "Poor Alex" << endl;
}
