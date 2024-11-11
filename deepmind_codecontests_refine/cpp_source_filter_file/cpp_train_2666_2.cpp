#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int maks = 0, vol = 0, licznik = 0;
  while (licznik < n) {
    string a;
    cin >> a;
    licznik += a.size();
    for (int i = 0; i < licznik; i++) {
      int x = a[i] - 'A' + 'A';
      if (x >= 65 && x <= 90) vol++;
    }
    maks = max(maks, vol);
    licznik++;
    vol = 0;
  }
  cout << maks << endl;
}
