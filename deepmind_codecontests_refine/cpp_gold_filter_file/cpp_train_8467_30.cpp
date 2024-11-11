#include <bits/stdc++.h>
using namespace std;
int main() {
  long long array[51], x;
  array[0] = 0;
  array[1] = 1;
  for (int i = 2; i <= 50; i++) array[i] = array[i - 1] + array[i - 2];
  cin >> x;
  for (int i = 0; i < 51; i++) {
    if (array[i] == x) {
      if (x == 0 || x == 1 || x == 2)
        cout << array[i - i] << " " << array[i - i] << " " << array[i] << endl;
      else
        cout << array[i - 1] << " " << array[i - 3] << " " << array[i - 4]
             << endl;
      break;
    }
  }
  return 0;
}
