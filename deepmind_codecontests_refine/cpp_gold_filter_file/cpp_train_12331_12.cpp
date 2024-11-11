#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, m, medals = 0, cups = 0, shelves;
  cin >> c;
  cups += c;
  cin >> c;
  cups += c;
  cin >> c;
  cups += c;
  cin >> m;
  medals += m;
  cin >> m;
  medals += m;
  cin >> m;
  medals += m;
  cin >> shelves;
  int total = 0;
  total += medals / 10;
  if (medals % 10) total++;
  total += cups / 5;
  if (cups % 5) total++;
  if (total > shelves)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
