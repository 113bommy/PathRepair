#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N;
  cin >> N;
  string STR;
  cin >> STR;
  long long int TOTAL_STONES = 0;
  for (int i = 0; i < STR.length(); i++) {
    if (STR[i] == '-') {
      if (TOTAL_STONES - 1 >= 0) TOTAL_STONES--;
    } else if (STR[i] == '+') {
      TOTAL_STONES++;
    }
  }
  cout << TOTAL_STONES << endl;
}
