#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int odd_count = 0;
    int count_tot = 0;
    int even_not_palindrome = 0;
    while (n--) {
      string s;
      cin >> s;
      if (s.size() & 1) {
        odd_count++;
        count_tot++;
      } else {
        int length = s.size();
        int count1 = 0, count0 = 0;
        for (int i = 0; i < length; i++) {
          if (s[i] == '1') {
            count1++;
          } else {
            count0++;
          }
        }
        if (count1 % 2 == 0) {
          count_tot++;
        } else {
          even_not_palindrome++;
        }
      }
    }
    if (even_not_palindrome & 1) {
      count_tot += (even_not_palindrome - 1);
      count_tot += min(1, odd_count);
    } else {
      count_tot += (even_not_palindrome);
    }
    cout << count_tot << endl;
  }
}
