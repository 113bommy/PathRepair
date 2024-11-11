#include <bits/stdc++.h>
using namespace std;
char v[] = {'a', 'e', 'i', 'o', 'u'};
int main() {
  string a;
  cin >> a;
  string b;
  cin >> b;
  if (a.size() != b.size()) {
    cout << "no" << endl;
    exit(0);
  }
  for (int i = 0; i < a.size(); i++) {
    bool X = 0, Y = 0;
    char x = a[i];
    char y = b[i];
    for (int j = 0; j < 5; j++) {
      if (x == v[j]) X = 1;
      if (y == v[j]) Y = 1;
    }
    if (X != Y) {
      cout << "no" << endl;
      exit(0);
    }
  }
  cout << "Yes" << endl;
}
