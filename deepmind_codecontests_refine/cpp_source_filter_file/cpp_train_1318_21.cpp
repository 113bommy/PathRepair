#include <bits/stdc++.h>
using namespace std;
int main() {
  char string[1001];
  cin >> string;
  int i = 0, pearls = 0, links = 0;
  while (string[i] != '\0') {
    if (string[i] == 'o') {
      pearls++;
    } else {
      links++;
    }
    i++;
  }
  if (links == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (pearls == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (links % pearls == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
