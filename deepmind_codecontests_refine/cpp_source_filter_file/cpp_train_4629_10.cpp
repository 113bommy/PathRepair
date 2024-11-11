#include <bits/stdc++.h>
using namespace std;
enum OP { ADD, MINUS1, MINUS2, MULT, NOP };
struct Arith {
  long long res;
  OP op;
  Arith *lval, *rval;
  Arith(const long long &rs, const OP &o, Arith *const lv, Arith *const rv)
      : res(rs), op(o), lval(lv), rval(rv) {}
  Arith(const long long &rs) : res(rs), op(NOP), lval(NULL), rval(NULL) {}
};
vector<Arith *> num;
bool found = false;
Arith *sol = NULL;
void solve() {
  if (num.size() == 1) {
    if (num[0]->res == 24L) {
      found = true;
      sol = num[0];
    }
    return;
  }
  for (int i = 0; i < num.size(); ++i) {
    for (int j = i + 1; j < num.size(); ++j) {
      Arith *ll = num[i], *rr = num[j];
      num.erase(num.begin() + i);
      num.erase(num.begin() + (j - 1));
      for (int k = 0; k < NOP; ++k) {
        OP op = static_cast<OP>(k);
        Arith *c = NULL;
        switch (op) {
          case ADD:
            c = new Arith(ll->res + rr->res, ADD, ll, rr);
            break;
          case MINUS1:
            c = new Arith(ll->res - rr->res, MINUS1, ll, rr);
            break;
          case MINUS2:
            c = new Arith(rr->res - ll->res, MINUS2, rr, ll);
            break;
          case MULT:
            c = new Arith(ll->res * rr->res, MULT, ll, rr);
            break;
          default:
            break;
        }
        num.push_back(c);
        solve();
        if (found) return;
        num.pop_back();
      }
      num.insert(num.begin() + i, ll);
      num.insert(num.begin() + j, rr);
    }
  }
}
void printFormula(const Arith *const node) {
  if (node->lval->op != NOP) {
    printFormula(node->lval);
  }
  if (node->rval->op != NOP) {
    printFormula(node->rval);
  }
  cout << node->lval->res;
  switch (node->op) {
    case ADD:
      cout << " + ";
      break;
    case MINUS1:
      cout << " - ";
      break;
    case MINUS2:
      cout << " - ";
      break;
    case MULT:
      cout << " * ";
      break;
    default:
      break;
  }
  cout << node->rval->res << " = " << node->res << endl;
}
void padBefore(const long long &s, const long long &n) {
  for (long long i = s; i <= n - 1; ++i) {
    cout << (i + 1) << " - " << i << " = 1" << endl;
  }
}
void padAfter(const long long &n) {
  long long t = n / 2 - 2;
  while (t--) {
    cout << "24 * 1 = 24" << endl;
  }
}
int main() {
  long long n;
  cin >> n;
  if (n <= 3) {
    cout << "NO" << endl;
    return 0;
  }
  long long cnt = (n % 2 == 0 ? 4 : 5);
  for (long long i = 1; i <= cnt; ++i) {
    Arith *node = new Arith(i);
    num.push_back(node);
  }
  solve();
  if (found) {
    cout << "YES" << endl;
    padBefore(cnt + 1, n);
    printFormula(sol);
    padAfter(n);
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
