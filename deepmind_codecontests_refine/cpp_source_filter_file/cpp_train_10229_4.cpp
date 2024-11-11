#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b, n;
    cin >> a >> b >> n;
    int counter = 0;
    while ((a < n) && (b < n)) {
      if (a > b) {
        counter++;
        b += a;
      } else {
        counter++;
        a += b;
      }
    }
    cout << counter << endl;
  }
  return 0;
}
