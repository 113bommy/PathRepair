#include <bits/stdc++.h>
using namespace std;
const int NUM_LETTERS = 37,
          NUM_NAMES =
              (NUM_LETTERS - 11) * NUM_LETTERS * NUM_LETTERS * NUM_LETTERS,
          MAXN = 4006, NAME_SIZE = 4;
int letterToInt[300];
char intToLetter[NUM_LETTERS];
int nameToInt(string str) {
  while (((int)str.size()) < NAME_SIZE) str += ' ';
  int ans = 0;
  for (int i = 0; i <= 3; ++i)
    ans = ans * NUM_LETTERS + letterToInt[(int)str[i]];
  return ans;
}
string intToName(int code) {
  string str;
  for (int _ = 0; _ < 4; ++_, code /= NUM_LETTERS)
    str = intToLetter[code % NUM_LETTERS] + str;
  while (str.back() == ' ') str.pop_back();
  return str;
}
int opToCode[300];
char codeToOp[4] = {'#', '$', '^', '&'};
int n;
int nameToVar[NUM_NAMES], varToName[MAXN], expp[MAXN], ptr = 1, curName = 0;
int varOfExp[4 * MAXN * MAXN];
bool done[MAXN];
vector<string> outs;
int getExp(int i1, int i2, int op) { return i1 + MAXN * (i2 + MAXN * op); }
void add(int name) {
  nameToVar[varToName[ptr] = name] = ptr;
  ++ptr;
}
void read() {
  string line;
  cin >> line;
  int asgn = 0;
  for (; line[asgn] != '='; ++asgn)
    ;
  int opI = 0;
  for (; opI < ((int)line.size()) && opToCode[(int)line[opI]] < 0; ++opI)
    ;
  if (opI == ((int)line.size())) {
    int lval = nameToInt(line.substr(0, asgn));
    int rval = nameToInt(line.substr(asgn + 1));
    if (!nameToVar[rval]) add(rval);
    nameToVar[lval] = nameToVar[rval];
  } else {
    int lval = nameToInt(line.substr(0, asgn));
    int val1 = nameToInt(line.substr(asgn + 1, opI - asgn - 1));
    int val2 = nameToInt(line.substr(opI + 1));
    if (!nameToVar[val1]) add(val1);
    if (!nameToVar[val2]) add(val2);
    int curExp =
        getExp(nameToVar[val1], nameToVar[val2], opToCode[(int)line[opI]]);
    if (varOfExp[curExp]) {
      nameToVar[lval] = varOfExp[curExp];
    } else {
      int lvar = nameToVar[lval] = ptr++;
      varOfExp[expp[lvar] = curExp] = lvar;
    }
  }
}
void declare(int var) {
  if (varToName[var] < 0) {
    while (nameToVar[curName]) ++curName;
    varToName[var] = curName++;
  }
  if (done[var] || !expp[var]) return;
  done[var] = 1;
  int cur = expp[var], i1, i2, op;
  i1 = cur % MAXN, cur /= MAXN, i2 = cur % MAXN, cur /= MAXN, op = cur;
  declare(i1);
  declare(i2);
  string str;
  str += intToName(varToName[var]);
  str += '=';
  str += intToName(varToName[i1]);
  str += codeToOp[op];
  str += intToName(varToName[i2]);
  outs.emplace_back(str);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= NUM_LETTERS - 1; ++i) intToLetter[i] = -1;
  for (int i = 0; i <= 25; ++i) intToLetter[i] = i + 'a';
  for (int i = 0; i <= 9; ++i) intToLetter[i + 26] = i + '0';
  intToLetter[36] = ' ';
  for (int i = 0; i <= NUM_LETTERS - 1; ++i)
    letterToInt[(int)intToLetter[i]] = i;
  for (int i = 0; i <= 299; ++i) opToCode[i] = -1;
  opToCode['#'] = 0, opToCode['$'] = 1, opToCode['^'] = 2, opToCode['&'] = 3;
  for (int i = 0; i <= MAXN - 1; ++i) varToName[i] = -1;
  cin >> n;
  for (int _ = 0; _ <= n - 1; ++_) read();
  if (!nameToVar[nameToInt("res")] ||
      intToName(varToName[nameToVar[nameToInt("res")]]) == "res")
    return cout << 0 << endl, 0;
  if (!expp[nameToVar[nameToInt("res")]])
    return cout << "1\nres="
                << intToName(varToName[nameToVar[nameToInt("res")]]) << endl,
           0;
  varToName[nameToVar[nameToInt("res")]] = nameToInt("res");
  declare(nameToVar[nameToInt("res")]);
  cout << ((int)outs.size()) << '\n';
  for (auto &x : outs) cout << x << '\n';
  return 0;
}
