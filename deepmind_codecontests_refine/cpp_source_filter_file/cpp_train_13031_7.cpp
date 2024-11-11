#include <bits/stdc++.h>
using namespace std;
int parent[100001];
int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}
bool unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  parent[x] = y;
  return true;
}
int main() {
  int n, m;
  cin >> m >> n;
  int temp, temp2;
  for (temp = 1; temp <= 100001; temp++) parent[temp] = temp;
  int c = m;
  int happy = 0;
  for (temp = 0; temp < m; temp++) {
    int a, b;
    cin >> a >> b;
    happy += unite(a, b);
  }
  cout << n - happy << "\n";
}
