#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N;
  cin >> N;
  long long cash[5] = {100, 20, 10, 5, 1};
  long long bills = 0;
  for (int i = 0; i < sizeof(cash); i++) {
    if (N == 0) {
      break;
    }
    while (N / cash[i] >= 1) {
      N = N - cash[i];
      bills++;
    }
  }
  cout << bills << "\n";
}
