#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> lhs, pair<int, int> rhs) {
  if (lhs.second < rhs.second) {
    return true;
  }
  return false;
}
bool compare2(pair<int, int> lhs, pair<int, int> rhs) {
  if (lhs.first > rhs.first) {
    return true;
  }
  return false;
}
int HCF(int a, int b) {
  int m = ((b) ^ (((a) ^ (b)) & -((a) > (b))));
  int n = ((b) ^ (((a) ^ (b)) & -((a) < (b))));
  if (m % n == 0) return n;
  return HCF(n, m % n);
}
int main(int argc, char* argv[]) {
  long long int n, m;
  cin >> n >> m;
  int b;
  int B[n];
  for (int i = 0; i < n; i++) {
    B[i] = 0;
  }
  cin >> b;
  for (int i = 0; i < b; i++) {
    int temp;
    cin >> temp;
    B[temp] = 1;
  }
  int g, G[m];
  for (int i = 0; i < m; i++) {
    G[i] = 0;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int temp;
    cin >> temp;
    G[temp] = 1;
  }
  int LCM = (n * m) / HCF(n, m);
  for (int i = 0; i < n * m; i++) {
    int x = i % n;
    int y = i % m;
    if (B[x] == 1 || G[y] == 1) {
      B[x] = 1;
      G[y] = 1;
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (B[i] == 0) {
      flag = 1;
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    if (G[i] == 0) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << "No\n";
  else
    cout << "Yes\n";
  return 0;
}
