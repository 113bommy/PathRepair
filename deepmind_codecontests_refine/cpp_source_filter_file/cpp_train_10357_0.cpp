#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  map<int, string> dic;
  dic.insert(make_pair(0, "zero (nought)"));
  dic.insert(make_pair(1, "one"));
  dic.insert(make_pair(2, "two"));
  dic.insert(make_pair(3, "three"));
  dic.insert(make_pair(4, "four"));
  dic.insert(make_pair(5, "five"));
  dic.insert(make_pair(6, "six"));
  dic.insert(make_pair(7, "seven"));
  dic.insert(make_pair(8, "eight"));
  dic.insert(make_pair(9, "nine"));
  dic.insert(make_pair(10, "ten"));
  dic.insert(make_pair(11, "eleven"));
  dic.insert(make_pair(12, "twelve"));
  dic.insert(make_pair(13, "thirteen"));
  dic.insert(make_pair(14, "fourteen"));
  dic.insert(make_pair(15, "fifteen"));
  dic.insert(make_pair(16, "sixteen"));
  dic.insert(make_pair(17, "seventeen"));
  dic.insert(make_pair(18, "eighteen"));
  dic.insert(make_pair(19, "nineteen"));
  dic.insert(make_pair(20, "twenty"));
  dic.insert(make_pair(30, "thirty"));
  dic.insert(make_pair(40, "forty"));
  dic.insert(make_pair(50, "fifty"));
  dic.insert(make_pair(60, "sixty"));
  dic.insert(make_pair(70, "seventy"));
  dic.insert(make_pair(80, "eighty"));
  dic.insert(make_pair(90, "ninety"));
  if (s < 21)
    cout << dic[s] << endl;
  else if (s % 10 == 0)
    cout << dic[s] << endl;
  else
    cout << dic[s / 10 * 10] << '-' << dic[s % 10] << endl;
  return 0;
}
