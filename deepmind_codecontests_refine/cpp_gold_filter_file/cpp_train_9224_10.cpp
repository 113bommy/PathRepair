#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  string data[T];
  for (long long i = 0; i < T; ++i) {
    cin >> data[i];
  }
  for (long long i = 0; i < T; ++i) {
    bool found = false;
    for (long long j = i - 1; j >= 0 && !found; --j) {
      found = data[i] == data[j];
    }
    if (found) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
