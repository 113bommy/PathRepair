#include <bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 1;
bool pm[sz + 5];
vector<int> vp;
void seive() {
  for (int i = 3; i * i < sz; i += 2)
    if (!pm[i])
      for (int j = i * i; j < sz; j += i) pm[j] = 1;
  vp.push_back(2);
  for (int i = 3; i < sz; i += 2)
    if (!pm[i]) vp.push_back(i);
}
int main() {
  int n, m, i, j, k;
  seive();
  cin >> n;
  int one = 0, two = 0;
  for (i = 0; i < n; i++) {
    cin >> k;
    if (k == 1)
      one++;
    else
      two++;
  }
  if (two) {
    cout << 2;
    if (one) {
      cout << " 1";
      for (i = 0; i < two - 1; i++) cout << " " << 2;
      for (i = 0; i < one - 1; i++) cout << " " << 1;
    } else
      for (i = 0; i < two - 1; i++) cout << " " << 2;
  } else
    for (i = 0; i < one; i++) {
      if (i) cout << " ";
      cout << i;
    }
  cout << endl;
  return 0;
}
