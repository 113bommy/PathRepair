#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a[5];
  for (int i = 0; i < 5; i++) cin >> a[i];
  int n;
  cin >> n;
  string s[n];
  vector<int> vect(n, 0);
  vector<int> vect1;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    int j = 0;
    if (s[i] == "XXL") j = 4;
    if (s[i] == "XL") j = 3;
    if (s[i] == "L") j = 2;
    if (s[i] == "M") j = 1;
    if (s[i] == "S") j = 0;
    while (1) {
      if (a[j] > 0) {
        a[j] = a[j] - 1;
        vect1.push_back(j);
        break;
      } else if (j + 1 < 5 and a[j + 1] > 0) {
        a[j + 1] = a[j + 1] - 1;
        vect1.push_back(j + 1);
        break;
      } else if (j - 1 >= 0 and a[j - 1] > 0) {
        a[j - 1] = a[j - 1] - 1;
        vect1.push_back(j - 1);
        break;
      } else if (j + 2 < 5 and a[j + 2] > 0) {
        a[j + 2] -= 1;
        vect1.push_back(j + 2);
        break;
      } else if (j - 2 >= 0 and a[j - 2] > 0) {
        a[j - 2] -= 1;
        vect1.push_back(j - 2);
        break;
      } else if (j + 3 < 5 and a[j + 3] > 0) {
        a[j + 3] -= 1;
        vect1.push_back(j + 3);
        break;
      } else if (j - 3 >= 0 and a[j - 3] > 0) {
        a[j - 3] -= 1;
        vect1.push_back(j - 3);
        break;
      } else if (j + 4 < 5 and a[j + 4] > 0) {
        a[j + 4] -= 1;
        vect1.push_back(j + 4);
        break;
      } else if (j - 4 >= 0 and a[j - 4] > 0) {
        a[j - 4] -= 1;
        vect1.push_back(j - 4);
        break;
      }
    }
  }
  for (auto i = vect1.begin(); i != vect1.end(); i++) {
    if (*i == 0)
      cout << "S" << endl;
    else if (*i == 1)
      cout << "M" << endl;
    else if (*i == 2)
      cout << "L" << endl;
    else if (*i == 3)
      cout << "XL" << endl;
    else if (*i == 4)
      cout << "XXL" << endl;
  }
}
