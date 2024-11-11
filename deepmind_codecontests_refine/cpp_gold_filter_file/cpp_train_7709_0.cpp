#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  list<int> lst;
  auto itr = lst.end();
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a;
    if (a == 0) {
      cin >> b;
      lst.insert(itr, b);
      itr--;
    }
    if (a == 1) {
      cin >> b;
      if (b >= 0) {
        for (int j = 0; j < b; j++) {
          itr++;
        }
      } else {
        for (int j = 0; j < abs(b); j++) {
          itr--;
        }
      }
    }
    if (a == 2) {
      itr = lst.erase(itr);
    }
  }
  for (auto itr = lst.begin(); itr != lst.end(); itr++) {
    cout << *itr << endl;
  }
}

