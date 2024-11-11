#include <bits/stdc++.h>
using namespace std;
int book[10001], n, cont;
set<int> read;
set<int>::iterator it1;
int main() {
  cin >> n;
  int j = 1;
  for (int i = 1; i <= n; i++) cin >> book[i];
  while (j <= n) {
    do {
      read.insert(book[j]);
      read.erase(j++);
    } while (!read.empty());
    cont++;
  }
  cout << cont << endl;
}
