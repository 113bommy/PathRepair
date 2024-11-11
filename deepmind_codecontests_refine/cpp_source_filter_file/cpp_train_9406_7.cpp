#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const double PI = acos(-1.0);
enum {};
int D[100005], C[100005];
int main() {
  string S;
  cin >> S;
  stack<pair<char, int> > K;
  for (int i = 0; i < S.size(); ++i) switch (S[i]) {
      case '(':
      case '[':
        K.push(pair<char, int>(S[i], i));
        C[i] = D[i] = -1;
        break;
      case ')':
      case ']':
        if (K.empty() || (S[i] == ']' && K.top().first != '[' ||
                          S[i] == ')' && K.top().first != '(')) {
          C[i] = D[i] = -1;
          while (!K.empty()) K.pop();
        } else {
          pair<char, int> t = K.top();
          K.pop();
          C[i] = D[i] = t.second;
          if (D[i] > 0 && (S[D[i] - 1] == ')' || S[D[i] - 1] == ']') &&
              C[D[i] - 1] != -1)
            C[i] = C[D[i] - 1];
        }
        break;
    }
  string r = "";
  int n = -1;
  for (int i = S.size() - 1; i >= 0; --i)
    if (C[i] != -1) {
      int t = 0;
      for (int j = C[i]; j <= i; ++j)
        if (S[j] == '[') ++t;
      if (t > n) n = t, r = S.substr(C[i], i - C[i] + 1);
      i = C[i];
    }
  cout << n << endl << r << endl;
  return 0;
}
