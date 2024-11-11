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
  else if (db == 9 && da == 1)
    cout << "999"
         << " "
         << "1000";
  else
    cout << "-1";
}
