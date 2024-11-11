#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string str1[4] = {"|#.#.#.#.#.#.#.#.#.#.#.|D|)", "|#.#.#.#.#.#.#.#.#.#.#.|.|",
                    "|........................|",
                    "|#.#.#.#.#.#.#.#.#.#.#.|.|)"};
  if (n <= 4) {
    cout << "+------------------------+" << endl;
    for (int i = 0; i < n; i++) str1[i][1] = 'O';
    cout << str1[0] << endl;
    cout << str1[1] << endl;
    cout << str1[2] << endl;
    cout << str1[3] << endl;
    cout << "+------------------------+" << endl;
  }
  if (n > 4 && n <= 34) {
    for (int i = 0; i < 4; i++) str1[i][1] = 'O';
    cout << "+------------------------+" << endl;
    n -= 4;
    long long int d = n / 3;
    long long int res = n % 3;
    for (long long int i = 0; i < 4; i++) {
      long long int x = 3;
      for (long long int j = 0; j < d; j++) {
        if (i != 2) {
          str1[i][x] = 'O';
          x += 2;
        }
      }
    }
    for (int i = 0; i < res; i++) {
      if (i != 2) str1[i][3 + d * 2] = 'O';
    }
    cout << str1[0] << endl;
    cout << str1[1] << endl;
    cout << str1[2] << endl;
    cout << str1[3] << endl;
    cout << "+------------------------+" << endl;
  }
}
int main() { solve(); }
