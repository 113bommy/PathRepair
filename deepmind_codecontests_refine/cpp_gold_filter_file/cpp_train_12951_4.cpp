#include <bits/stdc++.h>
using namespace std;
string a, b, c;
int ta, tb, nodo, sig[100 + 5][26], T[100 + 5], memo[100 + 5][100 + 5][100 + 5];
bool term[100 + 5];
void add(string s) {
  int tam = s.length(), u = 0;
  for (int i = 0; i < tam; ++i) {
    int c = s[i] - 'A';
    if (!sig[u][c]) {
      sig[u][c] = nodo++;
    }
    u = sig[u][c];
  }
  term[u] = 1;
}
void aho() {
  deque<int> Q;
  for (int i = 0; i < 26; ++i) {
    int v = sig[0][i];
    if (v) {
      T[v] = 0;
      Q.push_back(v);
    }
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop_front();
      for (int i = 0; i < 26; ++i) {
        int v = sig[u][i], x = sig[T[u]][i];
        if (v) {
          T[v] = x;
          term[v] |= term[x];
          Q.push_back(v);
        } else
          sig[u][i] = x;
      }
    }
  }
}
int f(int pa, int push_back, int nodo) {
  if (pa == ta || push_back == tb) return 0;
  int &ret = memo[pa][push_back][nodo];
  if (ret != -1) return ret;
  ret = 0;
  if (a[pa] == b[push_back]) {
    int c = a[pa] - 'A';
    int v = sig[nodo][c];
    if (!term[v]) {
      ret = 1 + f(pa + 1, push_back + 1, v);
    }
  }
  ret = max(ret, max(f(pa + 1, push_back, nodo), f(pa, push_back + 1, nodo)));
  return ret;
}
void rec(int pa, int push_back, int nodo) {
  if (pa == ta || push_back == tb) return;
  int res = f(pa, push_back, nodo);
  bool ok = 0;
  if (a[pa] == b[push_back]) {
    int c = a[pa] - 'A';
    int v = sig[nodo][c];
    if (!term[v]) {
      if (res == 1 + f(pa + 1, push_back + 1, v)) {
        ok = 1;
        printf("%c", a[pa]);
        rec(pa + 1, push_back + 1, v);
      }
    }
  }
  if (!ok) {
    if (res == f(pa + 1, push_back, nodo)) {
      rec(pa + 1, push_back, nodo);
    } else {
      rec(pa, push_back + 1, nodo);
    }
  }
}
int main() {
  cin >> a >> b >> c;
  ta = a.length(), tb = b.length();
  nodo = 1;
  memset(sig, 0, sizeof(sig));
  add(c);
  aho();
  memset(memo, -1, sizeof(memo));
  int res = f(0, 0, 0);
  if (res != 0)
    rec(0, 0, 0);
  else
    printf("0");
  puts("");
}
