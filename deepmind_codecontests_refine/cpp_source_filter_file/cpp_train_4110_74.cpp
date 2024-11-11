#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int scorea = 0, scoreb = 0;
  scorea = max(((3 * a) / 10), ((a) - ((c / 250) * c)));
  scoreb = max(((3 * b) / 10), ((b) - ((d / 250) * d)));
  if (scorea > scoreb) cout << "Misha";
  if (scorea == scoreb) cout << "Tie";
  if (scorea < scoreb) cout << "Vasya";
  return 0;
}
