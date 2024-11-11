#include <bits/stdc++.h>
using namespace std;
int INF = 1000000007;
string FILENAME = "input";
string FILEINPUT = FILENAME;
void writeln(int a);
void writeln(int a, int b);
void writeln(int a, int b, int c);
void writeln(int a, int b, int c, int d);
void writeln(vector<int>& a);
void readln(int& a);
void readln(int& a, int& b);
void readln(int& a, int& b, int& c);
void readln(int& a, int& b, int& c, int& d);
void readln(vector<int>& a, int n);
struct graph {
  vector<vector<int>> edges;
  int n;
  graph(int n);
  graph(int n, int m);
  graph();
  void createGraph(int n);
  void add_edge(int u, int v);
  void add_or_edge(int u, int v);
  void writelnMatrix();
  void writeln();
};
int n, m, k, x;
vector<int> a;
void run() {
  string s, s1;
  getline(cin, s);
  getline(cin, s1);
  int a = 0, b = 0;
  for (int i = 0; i < s.size(); i += 2)
    if (s[i] == '[') {
      if (s1[i] == '8')
        b++;
      else if (s1[i] == '(')
        a++;
    } else if (s[i] == '(') {
      if (s1[i] == '8')
        a++;
      else if (s1[i] == '[')
        b++;
    } else if (s[i] == '8') {
      if (s1[i] == '(')
        b++;
      else if (s1[i] == '[')
        a++;
    }
  printf(a > b ? "TEAM 1 WINS\n" : a == b ? "TIE\n" : "TEAM 2 WINS\n");
}
int main() {
  run();
  return 0;
}
graph::graph(int n) {
  this->n = n;
  edges.resize(n);
  int t;
  for (int i = 0; i < n; i++) {
    edges[i].resize(n);
    for (int j = 0; j < n; j++) readln(t), edges[i][j] = t == '1';
  }
}
graph::graph(int n, int m) {
  this->n = n;
  edges.resize(n);
  int u, v;
  for (int i = 0; i < m; i++) readln(u, v), add_edge(u - 1, v - 1);
}
void graph::add_edge(int u, int v) { edges[u].push_back(v); }
void graph::add_or_edge(int u, int v) {
  edges[u].push_back(v);
  edges[v].push_back(u);
}
graph::graph(){};
void graph::createGraph(int n) { edges.resize(n); }
void graph::writeln() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < edges[i].size(); j++) ::writeln(i, edges[i][j]);
}
void graph::writelnMatrix() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d ", edges[i][j]);
    printf("\n");
  }
}
void readln(vector<int>& f, int n) {
  int x;
  for (int i = 1; i <= n; i++) {
    readln(x);
    f.push_back(x);
  }
}
void writeln(vector<int>& f) {
  for (int i = 0; i < f.size(); i++)
    printf("%d%c", f[i], i == f.size() - 1 ? '\n' : ' ');
}
void writeln(int a) { printf("%d\n", a); }
void writeln(int a, int b) { printf("%d %d\n", a, b); }
void writeln(int a, int b, int c) { printf("%d %d %d\n", a, b, c); }
void writeln(int a, int b, int c, int d) {
  printf("%d %d %d %d\n", a, b, c, d);
}
void readln(int& a) { scanf("%d", &a); }
void readln(int& a, int& b) { scanf("%d %d", &a, &b); }
void readln(int& a, int& b, int& c) { scanf("%d %d %d", &a, &b, &c); }
void readln(int& a, int& b, int& c, int& d) {
  scanf("%d %d %d %d", &a, &b, &c, &d);
}
