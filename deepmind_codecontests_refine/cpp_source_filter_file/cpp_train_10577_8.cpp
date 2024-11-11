#include <bits/stdc++.h>
int bit[4][12][12][1010] = {0}, n;
void update(int x, int y, int z, int i, int val) {
  while (i <= n) {
    bit[x][y][z][i] += val;
    i = i + (i & (-i));
  }
}
int sum(int x, int y, int z, int i) {
  int s = 0;
  while (i > 0) {
    s += bit[x][y][z][i];
    i = i - (i & (-i));
  }
  return s;
}
int getNumber(char a) {
  if (a == 'A')
    return 0;
  else if (a == 'T')
    return 1;
  else if (a == 'G')
    return 2;
  else if (a == 'C')
    return 3;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::string str;
  std::cin >> str;
  n = str.length();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 10; ++j) {
      update(getNumber(str[i - 1]), j, i % j, i, 1);
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int flip;
    std::cin >> flip;
    if (flip == 1) {
      int place;
      char c;
      std::cin >> place >> c;
      for (int j = 1; j <= 10; ++j) {
        update(getNumber(str[place - 1]), j, place % j, place, -1);
        update(getNumber(c), j, place % j, place, 1);
      }
      str[place - 1] = c;
    } else {
      int l, r, ans = 0;
      std::string theOtherString;
      std::cin >> l >> r >> theOtherString;
      int lengthOfTheOtherString = theOtherString.length();
      for (int i = 1; i <= lengthOfTheOtherString; ++i) {
        ans += sum(getNumber(theOtherString[i - 1]), lengthOfTheOtherString,
                   (l + i - 1) % lengthOfTheOtherString, r) -
               sum(getNumber(theOtherString[i - 1]), lengthOfTheOtherString,
                   (l + i - 1) % lengthOfTheOtherString, l - 1);
      }
      std::cout << ans << "\n";
    }
  }
}
