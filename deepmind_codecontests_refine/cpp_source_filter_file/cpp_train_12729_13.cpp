#include <bits/stdc++.h>
using namespace std;
bool has_alphabet(std::string const &s) {
  std::bitset<26> alphabet;
  for (char c : s) {
    if (c >= 'A' && c <= 'Z')
      alphabet.set(c - 'A');
    else if (c >= 'a' && c <= 'z')
      alphabet.set(c - 'a');
  }
  return alphabet.count();
}
int main() {
  string kata1, kata2, kataAkhir;
  cin >> kata1;
  cin >> kata2;
  cin >> kataAkhir;
  string op;
  kata1 += kata2;
  sort(kata1.begin(), kata1.end());
  sort(kataAkhir.begin(), kataAkhir.end());
  if (kata1 == kataAkhir)
    cout << "Yes";
  else
    cout << "No";
}
