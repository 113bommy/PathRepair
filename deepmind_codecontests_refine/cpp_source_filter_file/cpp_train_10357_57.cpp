#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(istream::failbit | istream::badbit);
  }
} _;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
template <class T, class second>
void smax(T& a, const second& b) {
  if (b > a) a = b;
}
template <class T, class second>
void smin(T& a, const second& b) {
  if (b < a) a = b;
}
template <class T, class second>
T pop_begin(second& a) {
  auto it = a.begin();
  T ret = *it;
  a.erase(it);
  return ret;
}
signed main() {
  int N;
  cin >> N;
  if (N == 0)
    cout << "zero" << endl;
  else if (10 <= N && N < 20) {
    vector<string> which = {"ten",      "eleven",  "twelve",  "thirteen",
                            "fourteen", "fifteen", "sixteen", "seventeen",
                            "eighteen", "nineteen"};
    cout << which[N - 10] << endl;
  } else {
    vector<string> tens = {"",      "",      "twenty",  "thirty", "fourty",
                           "fifty", "sixty", "seventy", "eighty", "ninety"};
    cout << tens[N / 10];
    if (N / 10 && N % 10) cout << '-';
    N %= 10;
    vector<string> units = {"",     "one", "two",   "three", "four",
                            "five", "six", "seven", "eight", "nine"};
    cout << units[N] << endl;
  }
}
