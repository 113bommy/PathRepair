#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20) + 1;
const int OO = (1 << 30);
const int TRUE = 1, FALSE = 2, VAR = 4;
int n;
char formula[MAXN];
int combine(int v1, int v2, char type) {
  if (v1 > v2) return combine(v2, v1, type);
  if (type == '|') {
    if (v1 == TRUE) return TRUE;
    if (v1 == FALSE) return v2;
    if (v1 == VAR) return VAR | TRUE;
  }
  if (type == '&') {
    if (v1 == TRUE) return v2;
    if (v1 == FALSE) return FALSE;
    if (v1 == VAR) return VAR | FALSE;
  }
  if (type == '^') {
    if (v1 == TRUE) {
      if (v2 == TRUE) return FALSE;
      if (v2 == FALSE) return TRUE;
      if (v2 == VAR) return VAR;
    }
    if (v1 == FALSE) return v2;
    if (v1 == VAR) return TRUE | FALSE;
  }
  throw 17;
}
struct Node {
  char type;
  int value;
  Node *left, *right;
  Node(char t) : type(t), value(0), left(NULL), right(NULL) {
    if (t == '0') value = FALSE;
    if (t == '1') value = TRUE;
    if (t == '?') value = VAR;
  }
  void print(int depth = 0) {
    if (left != NULL) left->print(depth + 1);
    for (int i = 0; i < (depth); i++) printf(" ");
    printf("%c\n", type);
    if (right != NULL) right->print(depth + 1);
  }
  void printFormula() {
    if (left != NULL) {
      printf("(");
      left->printFormula();
    }
    printf("%c", type);
    if (right != NULL) {
      right->printFormula();
      printf(")");
    }
  }
  void computeValue() {
    if (value != 0) return;
    left->computeValue();
    right->computeValue();
    for (int i = 0; i < (3); i++)
      for (int j = 0; j < (3); j++) {
        if ((left->value & (1 << i)) and (right->value & (1 << j)))
          value |= combine(1 << i, 1 << j, type);
      }
  }
};
Node* parse(int& idx, int depth = 0) {
  char c = formula[idx];
  if (0)
    for (int i = 0; i < (depth); i++)
      if (0) cout << " ";
  if (0)
    cout << "parse("
         << "idx"
         << ":" << idx << " "
         << "c"
         << ":" << c << " "
         << ")\n";
  if (c == '0' or c == '1' or c == '?') {
    idx++;
    return new Node(c);
  }
  Node* res = new Node(' ');
  idx++;
  res->left = parse(idx, depth + 1);
  res->type = formula[idx];
  idx++;
  res->right = parse(idx, depth + 1);
  idx++;
  return res;
}
void solve() {
  int idx = 0;
  Node* root = parse(idx);
  root->computeValue();
  printf("%s\n", (root->value & VAR) ? "YES" : "NO");
}
int main() {
  scanf("%d%s", &n, formula);
  if (0) printf("%s\n", formula);
  solve();
  return 0;
}
