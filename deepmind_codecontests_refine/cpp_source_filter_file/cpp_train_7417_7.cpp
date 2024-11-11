#include <bits/stdc++.h>
using namespace std;
int main() {
  char first[105], second[105];
  int t;
  cin >> t;
  while (t--) {
    cin >> first;
    int len = strlen(first);
    cout << first[0];
    for (int i = 1; i < len; i += 3) {
      cout << first[i];
    }
    cout << endl;
  }
}
