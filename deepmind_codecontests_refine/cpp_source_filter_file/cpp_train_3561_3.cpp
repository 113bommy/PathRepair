#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  long long n1, n2;
  int numB = 0, numW = 0;
  bool isStartB = true;
  for (int i = 0; i < n; i++) {
    cin >> n1;
    numB += n1 / 2;
    numW += n1 / 2;
    if (n1 % 2 == 1) {
      if (isStartB) {
        numB++;
      } else {
        numW++;
      }
    }
    isStartB = !isStartB;
  }
  cout << min(numB, numW);
}
