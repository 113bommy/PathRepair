#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t1, t2;
  string s;
  cin >> n;
  cout << "+------------------------+" << endl;
  t1 = (n - 4) / 3;
  t2 = t1;
  if (((n - 4) - (t1 * 3)) > 0) t2++;
  s = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
  if (n >= 1) s[1] = 'O';
  for (int i = 0; i < t2; i++) s[(i * 2) + 3] = 'O';
  cout << s << endl;
  t2 = t1;
  if (((n - 4) - (t1 * 3)) > 1) t2++;
  s = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
  if (n >= 2) s[1] = 'O';
  for (int i = 0; i < t2; i++) s[(i * 2) + 3] = 'O';
  cout << s << endl;
  cout << '|';
  if (n >= 3)
    cout << "O.......................|" << endl;
  else
    cout << "........................|" << endl;
  t2 = t1;
  s = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
  if (n > 3) s[1] = 'O';
  for (int i = 0; i < t2; i++) s[(i * 2) + 3] = 'O';
  cout << s << endl;
  cout << "+------------------------+";
  return 0;
}
