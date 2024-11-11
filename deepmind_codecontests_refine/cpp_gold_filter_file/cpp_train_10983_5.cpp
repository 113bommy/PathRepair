#include <bits/stdc++.h>
using namespace std;
int main() {
  char letra;
  vector<char> v;
  char comp;
  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  while (cin >> letra) {
    v.push_back(letra);
    comp = toupper(letra);
    if (letra == comp) {
      sum1++;
    } else
      sum2++;
    sum3++;
  }
  if (sum1 > sum2) {
    for (int i = 0; i < sum3; i++) {
      v[i] = toupper(v[i]);
      cout << v[i];
    }
  } else if (sum1 < sum2 or sum1 == sum2) {
    for (int i = 0; i < sum3; i++) {
      v[i] = tolower(v[i]);
      cout << v[i];
    }
  } else
    cout << "error" << endl;
  return 0;
}
