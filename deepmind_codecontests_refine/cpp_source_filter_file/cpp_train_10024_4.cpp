#include <bits/stdc++.h>
using namespace std;
int main() {
  int td_sold;
  cin >> td_sold;
  int max_num = -1, max_place = 0;
  int min_num = 100, min_place = 0;
  int input;
  for (int i = 1; i <= td_sold; i++) {
    cin >> input;
    if (input > max_num) {
      max_num = input;
      max_place = i;
    }
    if (input < min_num) {
      min_num = input;
      min_place = i;
    }
  }
  int minus = 0;
  if (min_place < max_place) minus = 2;
  cout << max_place - 1 + td_sold - min_place - minus;
}
