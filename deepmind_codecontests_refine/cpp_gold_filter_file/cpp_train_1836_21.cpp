#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
string s;
int a[4], b[4];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mp["C"] = 0;
  mp["C#"] = 1;
  mp["D"] = 2;
  mp["D#"] = 3;
  mp["E"] = 4;
  mp["F"] = 5;
  mp["F#"] = 6;
  mp["G"] = 7;
  mp["G#"] = 8;
  mp["A"] = 9;
  mp["B"] = 10;
  mp["H"] = 11;
  cin >> s;
  a[1] = mp[s];
  cin >> s;
  a[2] = mp[s];
  cin >> s;
  a[3] = mp[s];
  sort(a + 1, a + 4);
  do {
    for (int i = 1; i <= 3; i++) b[i] = a[i];
    if (b[2] < b[1]) {
      b[2] += 12;
      b[3] += 12;
    }
    if (b[3] < b[2]) {
      b[3] += 12;
    }
    if (b[2] - b[1] == 4 && b[3] - b[2] == 3) {
      cout << "major" << endl;
      return 0;
    }
    if (b[2] - b[1] == 3 && b[3] - b[2] == 4) {
      cout << "minor" << endl;
      return 0;
    }
  } while (next_permutation(a + 1, a + 3 + 1));
  cout << "strange" << endl;
  return 0;
}
