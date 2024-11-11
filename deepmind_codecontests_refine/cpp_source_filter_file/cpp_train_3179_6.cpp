#include <bits/stdc++.h>
using namespace std;
int main() {
  long long temp = 0, a = 0, z = 0, b = 0, c = 0, d = 0, i = 0, j = 0, h1 = 0,
            h2 = 0, hour = 0, day = 0;
  ostringstream oss, tss;
  cin >> a;
  long long mas[a];
  if (a == 1) {
    cin >> z;
    cout << z;
    return 0;
  }
  for (long long i = 0; i < a; i++) {
    cin >> z;
    mas[i] = z;
  }
  sort(mas, mas + a);
  if ((a % 2) == 0) {
    d = a / 2;
  } else {
    d = a / 2 + 1;
  }
  for (long long i = 0; i < d; i++) {
    if ((i >= (a - i - 1))) {
      if ((mas[i] >= h2)) {
        cout << "Impossible";
        return 0;
      } else {
        oss << mas[i];
      }
    }
    if (i < a - i - 1) {
      if ((mas[i] < mas[a - i - 1])) {
        oss << mas[i] << " " << mas[a - i - 1] << " ";
        h2 = mas[a - i - 1];
      } else {
        cout << "Impossible";
        return 0;
      }
    }
  }
  cout << oss.str();
  return 0;
}
