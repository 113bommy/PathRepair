#include <bits/stdc++.h>
using namespace std;
string s;
int kapares[500000 + 1];
struct circuit {
  char circuit_type;
  long long sqrtC;
  int minnie_i;
  vector<circuit*> elements;
  circuit(int i, int j) {
    if (i == j) {
      sqrtC = 1;
      circuit_type = '*';
      return;
    }
    for (int k = i + 1; k <= j - 1; k++)
      if (s[k] == '(' || s[k] == '*') {
        circuit* c = new circuit(k, kapares[k]);
        elements.push_back(c);
        k = kapares[k];
      } else if (s[k] == 'P')
        circuit_type = 'P';
      else if (s[k] == 'S')
        circuit_type = 'S';
    if (circuit_type == 'S') {
      minnie_i = 0;
      for (int i = 0; i < elements.size(); i++)
        if (elements[i]->sqrtC < elements[minnie_i]->sqrtC) minnie_i = i;
      sqrtC = elements[minnie_i]->sqrtC;
    } else if (circuit_type == 'P') {
      sqrtC = 0;
      for (auto& c : elements) sqrtC += c->sqrtC;
    }
  }
  void propagate(vector<long long>& ans, long long RsqrtC) {
    if (circuit_type == '*') {
      ans.push_back(RsqrtC);
      return;
    } else if (circuit_type == 'S') {
      for (int i = 0; i < elements.size(); i++)
        elements[i]->propagate(ans, i == minnie_i ? RsqrtC : 0);
    } else if (circuit_type == 'P') {
      for (auto& c : elements) c->propagate(ans, RsqrtC);
    }
  }
};
void solve() {
  long long r;
  cin >> r;
  getline(cin, s);
  s = s.substr(1);
  stack<int> open_P;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '(')
      open_P.push(i);
    else if (s[i] == ')') {
      kapares[i] = open_P.top();
      kapares[open_P.top()] = i;
      open_P.pop();
    } else if (s[i] == '*')
      kapares[i] = i;
    else
      kapares[i] = -1;
  circuit* root = new circuit(0, s.length() - 1);
  vector<long long> ans;
  root->propagate(ans, r * root->sqrtC);
  cout << "REVOLTING";
  for (const int& ri : ans) cout << ' ' << ri;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
