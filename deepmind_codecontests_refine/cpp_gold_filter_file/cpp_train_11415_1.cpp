#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, nak = 0, now = 0, three = 1;
  vector<long long> mas{1};
  cin >> a >> b;
  while (nak < mas.size()) {
    if (mas[nak] * 2 <= b) mas.push_back(mas[nak] * 2);
    if (mas[nak] >= a) now++;
    if (three * 3 <= b) {
      three *= 3;
      if (three <= b) mas.push_back(three);
    }
    nak++;
  }
  cout << now << "\n";
}
