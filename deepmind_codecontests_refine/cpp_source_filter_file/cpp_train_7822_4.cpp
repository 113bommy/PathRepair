#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
vector<char> c;
int main() {
  long long int a, b, i, j, mx = 0;
  cin >> a;
  for (i = 0; i < a; i++) {
    cin >> b;
    v.push_back(b);
  }
  i = 0;
  j = a - 1;
  while (1) {
    if (v[i] <= v[j] && v[i] > mx) {
      c.push_back('L');
      mx = v[i];
      i++;
    } else if (v[j] > mx) {
      c.push_back('R');
      mx = v[j];
      j--;
    } else if (v[i] > mx) {
      c.push_back('L');
      mx = v[j];
      break;
    } else {
      break;
    }
    if (i > j || i >= a || j < 0) {
      break;
    }
  }
  cout << c.size() << endl;
  for (i = 0; i < c.size(); i++) {
    cout << c[i];
  }
  return 0;
}
