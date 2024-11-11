#include <bits/stdc++.h>
using namespace std;
char arr[8][8];
int main() {
  int N;
  cin >> N;
  int fours = (1 << 29), sevens = (1 << 29), x, y;
  for (long long int i = (0); i < (N / 4); ++i) {
    if ((N - i * 4) % 7 == 0) {
      x = i;
      y = (N - 4 * i) / 7;
      if (x + y < fours + sevens) {
        fours = x;
        sevens = y;
      }
    }
  }
  if (fours == (1 << 29)) {
    cout << -1 << endl;
    return 0;
  }
  for (long long int i = (0); i < (fours); ++i) {
    cout << 4;
  }
  for (long long int i = (0); i < (sevens); ++i) {
    cout << 7;
  }
  cout << endl;
  return 0;
}
