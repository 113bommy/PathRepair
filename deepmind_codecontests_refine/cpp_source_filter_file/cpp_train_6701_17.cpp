#include <bits/stdc++.h>
using namespace std;
void imprime(vector<int> a) {
  cout << "----------------------------\n";
  for (int i = 1; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  int n, k;
  vector<int> p1, p2, q, s, tmp;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      q.push_back(0);
      continue;
    }
    int a;
    cin >> a;
    q.push_back(a);
  }
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      s.push_back(0);
      continue;
    }
    int a;
    cin >> a;
    s.push_back(a);
  }
  for (int i = 0; i <= n; i++) {
    p1.push_back(i);
    p2.push_back(i);
  }
  if (p1 == s) {
    cout << "NO\n";
    return 0;
  }
  for (int j = 1; j <= n; j++) {
    p2[q[j]] = p1[j];
  }
  if (q == s && p2 == s) {
    cout << "NO\n";
    return 0;
  }
  p2.clear();
  p2 = p1;
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      p2[q[j]] = p1[j];
    }
    tmp = p1;
    p1 = p2;
    p2 = tmp;
    bool flag = true;
    for (int j = 1; j <= n; j++) {
      if (p1[j] != s[j]) flag = false;
    }
    if (!flag)
      continue;
    else {
      if ((k - i + 1) % 2 == 0) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  p1.clear();
  p2.clear();
  for (int i = 0; i <= n; i++) {
    p1.push_back(i);
    p2.push_back(i);
  }
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      p2[j] = p1[q[j]];
    }
    tmp = p1;
    p1 = p2;
    p2 = tmp;
    bool flag = true;
    for (int j = 1; j <= n; j++) {
      if (p1[j] != s[j]) flag = false;
    }
    if (!flag)
      continue;
    else {
      if ((k - i + 1) % 2 == 0) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
