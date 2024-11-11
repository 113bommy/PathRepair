#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, d;
  string s;
  bool bul = false;
  cin >> d;
  while (d) {
    cin >> s >> a >> b;
    if (a >= 2400 && b > a) {
      bul = true;
    }
    d--;
  }
  if (bul) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
