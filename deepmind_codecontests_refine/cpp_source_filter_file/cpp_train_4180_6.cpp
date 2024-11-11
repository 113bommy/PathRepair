#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  char in1[10000], in2[10000], in3[10000];
  char ot1[10000], ot2[10000], ot3[10000];
  memset(in1, 0, sizeof(in1));
  memset(in2, 0, sizeof(in2));
  memset(in3, 0, sizeof(in3));
  int pos[10000];
  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    in1[i] = (i % 26) + 'a';
    in2[i] = (i / 26 % 26) + 'a';
    in3[i] = (i / 26 / 26) + 'a';
  }
  cout << "? " << in1 << endl;
  fflush(stdout);
  cin >> ot1;
  cout << "? " << in2 << endl;
  fflush(stdout);
  cin >> ot2;
  cout << "? " << in3 << endl;
  fflush(stdout);
  cin >> ot3;
  for (int i = 0; i < t.size(); i++) {
    pos[i] = (ot1[i] - 'a') + (ot2[i] - 'a') * 26 + (ot3[i] - 'a') * 26 * 26;
  }
  string k(t.size(), 'a');
  for (int i = 0; i < t.size(); i++) {
    k[pos[i]] = t[i];
  }
  cout << "! " << k << endl;
  fflush(stdout);
  return 0;
}
