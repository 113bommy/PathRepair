#include <bits/stdc++.h>
using namespace std;
const int LEN = 1000100;
int c, c1, num, kol, n, kol1;
string st;
vector<int> q;
int main() {
  q.push_back(1);
  c++;
  while (cin >> st) {
    if (st == "+")
      q.push_back(1), c++;
    else if (st == "-")
      q.push_back(-1), c1++;
    else if (st == "=") {
      cin >> num;
      break;
    }
  }
  n = num;
  num += c1;
  if (c * n < num || c > num + c1 * (n - 1)) {
    cout << "Impossible";
    return 0;
  }
  kol = num % c;
  kol1 = c - num;
  cout << "Possible" << endl;
  for (int i = 0; i < q.size(); i++) {
    if (q[i] == -1) {
      cout << 1 + min(max(kol1, 0), n - 1) << " ";
      kol1 -= min(max(kol1, 0), n - 1);
    } else {
      cout << max(1, num / c + int(kol > 0)) << " ";
      kol--;
    }
    if (i + 1 < q.size()) {
      if (q[i + 1] == -1)
        cout << "- ";
      else
        cout << "+ ";
    }
  }
  cout << "= ";
  cout << n;
  return 0;
}
