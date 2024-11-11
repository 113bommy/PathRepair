#include <bits/stdc++.h>
using namespace std;
string digits(int n) {
  string res;
  if (n == 0) return "0";
  while (n > 0) {
    res += (char)('0' + (n % 10));
    n /= 10;
  }
  return res;
}
int undigitsFromBack(const string& s) {
  int res = 0;
  for (int i = s.size() - 1; 0 <= i; --i) {
    res *= 10;
    res += s[i] - '0';
  }
  return res;
}
int zerosuffixes(int n) {
  int res = 0;
  while (n > 0 && n % 10 == 0) {
    ++res;
    n /= 10;
  }
  return res;
}
int countNines(const vector<int>& d1, const vector<int>& d2, string* ans1,
               string* ans2, int* trailing_zeros) {
  const int length = accumulate(d1.begin(), d1.end(), 0);
  vector<int> usable(10, 0);
  for (int i = 0; i <= 9; ++i) {
    usable[i] = min(d1[i], d2[9 - i]);
  }
  *trailing_zeros = min(d1[0] - usable[0], d2[0] - usable[9]);
  string prefix;
  prefix.reserve(length);
  ans1->clear();
  ans1->reserve(length);
  ans2->clear();
  ans2->reserve(length);
  for (int i = 1; i <= 9; ++i) {
    *ans1 += string(d1[i] - usable[i], '0' + i);
    *ans2 += string(d2[i] - usable[9 - i], '0' + i);
  }
  *ans1 += string(d1[0] - usable[0] - *trailing_zeros, '0');
  *ans2 += string(d2[0] - usable[9] - *trailing_zeros, '0');
  for (int i = 0; i <= 9; ++i) {
    *ans1 += string(usable[i], '0' + i);
    *ans2 += string(usable[i], '0' + 9 - i);
  }
  return accumulate(usable.begin(), usable.end(), *trailing_zeros);
}
int main(void) {
  string s;
  cin >> s;
  vector<int> d1(10, 0);
  for (int i = 0; i < s.size(); ++i) {
    ++d1[s[i] - '0'];
  }
  vector<int> d2(d1);
  int record = d1[0];
  string re1 = s;
  sort(re1.begin(), re1.end());
  reverse(re1.begin(), re1.end());
  string re2 = re1;
  for (int c1 = 1; c1 <= 5; ++c1) {
    int c2 = 10 - c1;
    if (d1[c1] > 0 && d2[c2] > 0) {
      --d1[c1];
      --d2[c2];
      string s1, s2;
      int trailing_zeros;
      int score = countNines(d1, d2, &s1, &s2, &trailing_zeros) + 1;
      ++d1[c1];
      ++d2[c2];
      if (score > record) {
        record = score;
        re1 = s1 + string(1, '0' + c1) + string(trailing_zeros, '0');
        re2 = s2 + string(1, '0' + c2) + string(trailing_zeros, '0');
      }
    }
  }
  cout << re1 << endl << re2 << endl;
}
