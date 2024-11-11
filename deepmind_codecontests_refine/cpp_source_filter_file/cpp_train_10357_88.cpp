#include <bits/stdc++.h>
using namespace std;
struct s {
  long long x, y;
};
bool cmp(s a, s b) { return a.x < b.x; }
long long gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  string s;
  cin >> s;
  string arr[] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
  string arr1[] = {"ten",   "twenty",  "thirty", "forty", "fifty",
                   "sixty", "seventy", "eighty", "ninety"};
  if (s == "11")
    cout << "eleven" << endl;
  else if (s == "12")
    cout << "twelve" << endl;
  else if (s == "13")
    cout << "thirteen" << endl;
  else if (s == "14")
    cout << "fourteen" << endl;
  else if (s == "15")
    cout << "fourteen" << endl;
  else if (s == "16")
    cout << "sixteen" << endl;
  else if (s == "17")
    cout << "seventeen" << endl;
  else if (s == "18")
    cout << "eighteen" << endl;
  else if (s == "19")
    cout << "nineteen" << endl;
  else if (s.size() == 1) {
    int num;
    stringstream ss;
    ss << s;
    ss >> num;
    cout << arr[num] << endl;
  } else {
    int num;
    stringstream ss;
    ss << s;
    ss >> num;
    cout << arr1[(num / 10) - 1];
    if (s[1] != '0') {
      cout << "-";
      num = num % 10;
      cout << arr[num];
    }
    cout << endl;
  }
}
