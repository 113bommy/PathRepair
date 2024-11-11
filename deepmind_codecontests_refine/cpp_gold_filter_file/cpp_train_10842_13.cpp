#include <bits/stdc++.h>
using namespace std;
int tab[1000];
int main() {
  for (int id = 21; id <= 50; id++)
    cout << ((min(id, 25) + id) % (2 + id % 3) > 0) << endl;
}
