#include <bits/stdc++.h>
using namespace std;
pair<int, int> A[200005];
int ans[200005], C[200005], n;
void form(int val) {
  for (int i = 0; i < n; i++) ans[i] = A[i].second;
  int a = -1, b = -1, c = -1;
  for (int i = 0; i < n; i++)
    if (A[i].first == val) {
      if (a == -1)
        a = i;
      else if (b == -1)
        b = i;
      else if (c == -1)
        c = i;
    }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  swap(ans[a], ans[b]);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  swap(ans[b], ans[c]);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  exit(0);
}
int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i].first;
    A[i].second = i + 1;
    C[A[i].first]++;
  }
  sort(A, A + n);
  int a = -1, b = -1;
  for (int i = 0; i < 2001; i++)
    if (C[i] == 2) {
      if (a == -1)
        a = i;
      else if (b == -1)
        b = i;
    } else if (C[i] >= 3) {
      form(i);
    }
  if (a == -1 || b == -1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int s1 = -1, s2 = -1;
  for (int i = 0; i < n; i++)
    if (A[i].first == a) {
      if (s1 == -1)
        s1 = i;
      else if (s2 == -1)
        ;
      s2 = i;
    }
  for (int i = 0; i < n; i++) ans[i] = A[i].second;
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  swap(ans[s1], ans[s2]);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  s1 = -1, s2 = -1;
  for (int i = 0; i < n; i++)
    if (A[i].first == b) {
      if (s1 == -1)
        s1 = i;
      else if (s2 == -1)
        ;
      s2 = i;
    }
  swap(ans[s1], ans[s2]);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
