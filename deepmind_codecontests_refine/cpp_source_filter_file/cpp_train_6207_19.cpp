#include <bits/stdc++.h>
using namespace std;
char in[100];
int main() {
  int n;
  for (int i = 0; i < 100; ++i) in[i] = 'a' + i % 24;
  while (cin >> n) {
    if (n % 2 == 0) {
      for (int i = 0; i < n / 2; ++i) cout << in[i % 25] << in[i % 24];
      cout << endl << 'z';
      for (int i = 0; i < n / 2 - 1; ++i)
        cout << in[(i + 2) % 24] << in[(i + 2) % 24];
      cout << 'z' << endl << 'y';
      for (int i = 0; i < n / 2 - 1; ++i)
        cout << in[(i + 3) % 24] << in[(i + 3) % 24];
      cout << 'y' << endl;
      for (int i = 0; i < n / 2; ++i)
        cout << in[(i + 4) % 24] << in[(i + 4) % 24];
      cout << endl;
    } else {
      for (int i = 0; i < n / 2; ++i) cout << in[i % 24] << in[i % 24];
      cout << 'z' << endl;
      for (int i = 0; i < n / 2; ++i)
        cout << in[(i + 1) % 24] << in[(i + 1) % 24];
      cout << 'z' << endl << 'y';
      for (int i = 0; i < n / 2; ++i)
        cout << in[(i + 3) % 24] << in[(i + 3) % 24];
      cout << endl << 'y';
      for (int i = 0; i < n / 2; ++i)
        cout << in[(i + 4) % 24] << in[(i + 4) % 24];
      cout << endl;
    }
  }
  return 0;
}
