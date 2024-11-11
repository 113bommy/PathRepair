#include <bits/stdc++.h>
using namespace std;
int main() {
  int da, db;
  cin >> da >> db;
  if (da == db)
    cout << da << "11"
         << " " << db << "12";
  else if (db == da + 1)
    cout << da << "99"
         << " " << db << "00";
  else if (da == 9 && db == 1)
    cout << "999"
         << " "
         << "1000";
  else
    cout << "-1";
}
