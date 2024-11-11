#include <bits/stdc++.h>
using namespace std;
int main() {
  char A[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  string str;
  cin >> str;
  int z = A[0];
  int k{0}, l{0}, n{0};
  for (int i = 0; i < str.length(); i++) {
    k = z - str[i];
    if (abs(k) > 13) {
      l += 26 - abs(k);
    } else {
      l = l + k;
    }
    z = str[i];
  }
  cout << l << endl;
  return 0;
}
