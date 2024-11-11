#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a, b;
  int counter;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    counter = 0;
    while (a != 0 && b != 0) {
      if (a > b) {
        counter += a / b;
        a = a % b;
      } else {
        counter += b / a;
        b = b % a;
      }
    }
    cout << counter << endl;
  }
}
