#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Node {
  Node *ch[2] = {0};
  bool hasBlack = 0, hasWhite = 0;
  bool isBlack = 0, isWhite = 0;
};
vector<pair<long long, long long> > ANS;
void FindAns(Node *root, int p, long long adr) {
  if (not root) return;
  if (root->hasBlack) {
    if (root->hasWhite) {
      FindAns(root->ch[0], p + 1, adr);
      FindAns(root->ch[1], p + 1, adr | (1LL << (31 - p)));
    } else {
      ANS.push_back(make_pair(adr, p));
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  Node *root = new Node();
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    stringstream ss(str);
    char pm, dot;
    long long a, b, c, d, x = 32;
    ss >> pm >> a >> dot >> b >> dot >> c >> dot >> d;
    if (not ss.eof()) ss >> dot >> x;
    long long adr = (a << 24) + (b << 16) + (c << 8) + d;
    adr >>= 32 - x;
    adr <<= 32 - x;
    Node *cur = root;
    for (int i = 31; i >= 32 - x; i--) {
      if (pm == '+') {
        if (cur->isBlack) {
          cout << "-1\n";
          exit(0);
        }
        cur->hasWhite = 1;
      } else {
        if (cur->isWhite) {
          cout << "-1\n";
          exit(0);
        }
        cur->hasBlack = 1;
      }
      bool b = adr & (1LL << i);
      if (not cur->ch[b]) cur->ch[b] = new Node();
      cur = cur->ch[b];
    }
    if (pm == '+') {
      if (cur->hasBlack) {
        cout << "-1\n";
        exit(0);
      }
      cur->hasWhite = 1;
      cur->isWhite = 1;
    } else {
      if (cur->hasWhite) {
        cout << "-1\n";
        exit(0);
      }
      cur->hasBlack = 1;
      cur->isBlack = 1;
    }
  }
  FindAns(root, 0, 0);
  cout << ANS.size() << "\n";
  int allBits = (1 << 8) - 1;
  for (auto it : ANS) {
    int a = it.first >> 24;
    int b = (it.first >> 16) & allBits;
    int c = (it.first >> 8) & allBits;
    int d = it.first & allBits;
    int x = it.second;
    cout << a << "." << b << "." << c << "." << d << "/" << x << "\n";
  }
  return 0;
}
