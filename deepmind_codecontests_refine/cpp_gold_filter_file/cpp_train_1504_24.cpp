#include <bits/stdc++.h>
using namespace std;
struct Statement {
  int value;
  string op;
  char judge;
};
struct Scope {
  int from;
  int to;
};
string getOp(string str, char judge) {
  if (judge == 'Y') return str;
  if (str == ">") return "<=";
  if (str == ">=") return "<";
  if (str == "<") return ">=";
  if (str == "<=") return ">";
  return "";
}
bool eval(string op, int limit, Scope &possible) {
  if (op == ">") {
    if (limit < possible.from) return true;
    if (limit >= possible.to) return false;
    possible.from = limit + 1;
    return true;
  }
  if (op == ">=") {
    if (limit < possible.from) return true;
    if (limit > possible.to) return false;
    possible.from = limit;
    return true;
  }
  if (op == "<") {
    if (limit > possible.to) return true;
    if (limit <= possible.from) return false;
    possible.to = limit - 1;
    return true;
  }
  if (op == "<=") {
    if (limit > possible.to) return true;
    if (limit < possible.from) return false;
    possible.to = limit;
    return true;
  }
  return false;
}
int main() {
  int N;
  cin >> N;
  vector<Statement> states(N);
  for (int i = 0; i < N; i++) {
    cin >> states[i].op >> states[i].value >> states[i].judge;
  }
  Scope possible;
  possible.from = -2000000000;
  possible.to = 2000000000;
  bool found = true;
  for (int i = 0; i < N; i++) {
    if (!eval(getOp(states[i].op, states[i].judge), states[i].value,
              possible)) {
      found = false;
      break;
    }
  }
  if (!found || possible.from > possible.to) {
    cout << "Impossible" << endl;
  } else {
    cout << possible.from << endl;
  }
  return 0;
}
