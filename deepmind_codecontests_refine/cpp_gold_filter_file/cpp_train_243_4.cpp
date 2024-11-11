#include <bits/stdc++.h>
using namespace std;
ifstream fin("roads.in");
ofstream fout("roads.out");
typedef struct muchie {
  int a;
  int b;
} muchie;
int parent[10009];
int rankS[10009];
int findS(int a) {
  if (parent[a] == a) {
    return a;
  }
  parent[a] = findS(parent[a]);
  return parent[a];
}
void unionS(int a, int b) {
  int n1 = findS(a);
  int n2 = findS(b);
  if (n1 == n2) {
    return;
  }
  rankS[n1] > rankS[n2] ? parent[n2] = n1 : parent[n1] = n2;
  if (rankS[n1] == rankS[n2]) {
    rankS[n2]++;
  }
}
void solve(int n, vector<muchie> muchii) {
  vector<muchie> toClose;
  vector<muchie> toOpen;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  for (auto muchie : muchii) {
    if (findS(muchie.a) != findS(muchie.b)) {
      unionS(muchie.a, muchie.b);
    } else {
      toClose.push_back(muchie);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (findS(1) != findS(i)) {
      unionS(1, i);
      toOpen.push_back(muchie{1, i});
    }
  }
  cout << toClose.size() << "\n";
  for (int i = 0; i < toClose.size(); i++) {
    cout << toClose[i].a << " " << toClose[i].b << " " << toOpen[i].a << " "
         << toOpen[i].b << "\n";
  }
}
int main() {
  int n, a, b;
  cin >> n;
  vector<muchie> muchii;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    muchii.push_back(muchie{a, b});
  }
  solve(n, muchii);
}
