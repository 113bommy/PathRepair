#include <bits/stdc++.h>
using namespace std;
long long se[110];
int main() {
  map<string, long long> mp;
  mp["C"] = 1;
  mp["C#"] = 2;
  mp["D"] = 3;
  mp["D#"] = 4;
  mp["E"] = 5;
  mp["F"] = 6;
  mp["F#"] = 7;
  mp["G"] = 8;
  mp["G#"] = 9;
  mp["A"] = 10;
  mp["B"] = 11;
  mp["H"] = 12;
  long long x = 5, I = 1;
  while (x--) {
    for (long long i = 0; i < 12; i++) {
      se[I++] = i + 1;
    }
  }
  string a, b, c;
  cin >> a >> b >> c;
  long long A = mp[a], B = mp[b], C = mp[c];
  if (se[A + 4] == B && se[A + 7] == C) return cout << "major\n", 0;
  if (se[A + 4] == C && se[A + 7] == B) return cout << "major\n", 0;
  if (se[B + 4] == A && se[B + 7] == C) return cout << "major\n", 0;
  if (se[B + 4] == C && se[B + 7] == A) return cout << "major\n", 0;
  if (se[C + 4] == B && se[C + 7] == A) return cout << "major\n", 0;
  if (se[C + 4] == A && se[C + 7] == B) return cout << "major\n", 0;
  if (se[A + 3] == B && se[A + 7] == C) return cout << "minor\n", 0;
  if (se[A + 3] == C && se[A + 7] == B) return cout << "minor\n", 0;
  if (se[B + 3] == A && se[B + 7] == C) return cout << "minor\n", 0;
  if (se[B + 3] == C && se[B + 7] == A) return cout << "minor\n", 0;
  if (se[C + 3] == B && se[C + 7] == A) return cout << "minor\n", 0;
  if (se[C + 3] == A && se[C + 7] == B) return cout << "minor\n", 0;
  cout << "strange\n";
  return 0;
}
