#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T) {
    long long input[3];
    long long sum = 0;
    long long output = 0;
    for (int i = 0; i < 3; i++) {
      cin >> input[i];
      sum += input[i];
    }
    output = sum / 2;
    cout << output << endl;
    T--;
  }
}
