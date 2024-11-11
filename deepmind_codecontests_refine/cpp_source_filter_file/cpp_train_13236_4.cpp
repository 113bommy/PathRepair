#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
const long double ERR = 1e-5;
const int MOD = 1e9 + 7;
bool areEqual(long double _n1, long double _n2) {
  return fabs(_n1 - _n2) < ERR;
}
string OUTCOME = "";
string PLAYERStart = "SRPSRPSRPP";
vector<string> PLAYER = {"PPPPPPPPPP", "SSSSSSSSSS", "RRRRRRRRRR",
                         "SRPSRPSRPS", "SRPSRPSRPS", "PRSPRSPRSP"};
vector<string> AI = {"RRRRRRRRRR RRRRRRRRRR", "PPPPPPPPPP PPPPPPPPPP",
                     "SSSSSSSSSS SSSSSSSSSS", "RPSRPSRPSR PSRPSRPSRP",
                     "RSRPSRPSRP PSRPSRPSRP", "RRPSRPSRPS RSPRSPRSPR"};
void testOutStrategy();
void playStrategy(string);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  testOutStrategy();
  if (OUTCOME == "LLWLLWLLWW")
    playStrategy(PLAYER[0]);
  else if (OUTCOME == "WLLWLLWLLL")
    playStrategy(PLAYER[1]);
  else if (OUTCOME == "LWLLWLLWLL")
    playStrategy(PLAYER[2]);
  else if (OUTCOME == "LLLLLLLLLW")
    playStrategy(PLAYER[3]);
  else if (OUTCOME == "LWWWWWWWWL")
    playStrategy(PLAYER[4]);
  else if (OUTCOME == "LLLLLLLLLL")
    playStrategy(PLAYER[5]);
  else
    cout << OUTCOME << '\n';
}
void playStrategy(string S) {
  for (int i = 0; i < S.length(); i++) {
    cout << S[i] << '\n';
    cout.flush();
    string verdict;
    getline(cin, verdict);
  }
}
void testOutStrategy() {
  for (int i = 0; i < 10; i++) {
    cout << PLAYERStart[i] << '\n';
    cout.flush();
    string verdict;
    getline(cin, verdict);
    OUTCOME += (verdict == "player" ? 'W' : 'L');
  }
}
