#include <bits/stdc++.h>
using namespace std;
map<int, string> m;
int s;
int main() {
  m.insert(make_pair(0, "zero"));
  m.insert(make_pair(1, "one"));
  m.insert(make_pair(2, "two"));
  m.insert(make_pair(3, "three"));
  m.insert(make_pair(4, "four"));
  m.insert(make_pair(5, "five"));
  m.insert(make_pair(6, "six"));
  m.insert(make_pair(7, "seven"));
  m.insert(make_pair(8, "eight"));
  m.insert(make_pair(9, "nine"));
  m.insert(make_pair(10, "ten"));
  m.insert(make_pair(11, "eleven"));
  m.insert(make_pair(12, "twelve"));
  m.insert(make_pair(13, "thirteen"));
  m.insert(make_pair(14, "fourteen"));
  m.insert(make_pair(15, "fifteen"));
  m.insert(make_pair(16, "sixteen"));
  m.insert(make_pair(17, "seventeen"));
  m.insert(make_pair(18, "eighteen"));
  m.insert(make_pair(19, "nineteen"));
  m.insert(make_pair(20, "twenty"));
  m.insert(make_pair(30, "thirty"));
  m.insert(make_pair(40, "fourty"));
  m.insert(make_pair(50, "fifty"));
  m.insert(make_pair(60, "sixty"));
  m.insert(make_pair(70, "seventy"));
  m.insert(make_pair(80, "eighty"));
  m.insert(make_pair(90, "ninety"));
  scanf("%d", &s);
  if (m.count(s)) {
    cout << m[s] << endl;
  } else {
    cout << m[(s / 10) * 10] << "-" << m[s % 10] << endl;
  }
  return 0;
}
