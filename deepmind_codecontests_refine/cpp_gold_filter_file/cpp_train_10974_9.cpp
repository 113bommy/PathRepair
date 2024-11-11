#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = ceil(double(n) / 2) * ceil(double(n) / 2);
  count += (n / 2) * (n / 2);
  cout << count << endl;
  for (int i = 0; i < n;) {
    for (int j = 0; j < n; j++)
      if (j % 2 == 0)
        cout << "C";
      else
        cout << ".";
    cout << endl;
    i++;
    if (i < n) {
      for (int j = 0; j < n; j++)
        if (j % 2 == 0)
          cout << ".";
        else
          cout << "C";
    }
    cout << endl;
    i++;
  }
}
