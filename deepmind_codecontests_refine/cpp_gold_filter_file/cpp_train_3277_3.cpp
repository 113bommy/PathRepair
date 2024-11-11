#include <bits/stdc++.h>
using namespace std;
void reverse(string *str, int i, int j) {
  if (i <= j) {
    char c = str->at(i);
    char r = str->at(j);
    str->at(i) = r;
    str->at(j) = c;
  }
}
int main() {
  string s, res;
  int days, aux, in;
  cin >> s;
  cin >> days;
  aux = s.length() / 2;
  int sums[aux];
  fill(sums, sums + sizeof(sums) / sizeof(int), 0);
  while (days--) {
    cin >> in;
    sums[in]++;
  }
  in = 0;
  for (int i = 1; i <= aux; i++) {
    in += sums[i];
    if (in % 2) {
      swap(s[i - 1], s[s.length() - i]);
    }
  }
  cout << s << endl;
}
