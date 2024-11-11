#include <bits/stdc++.h>
using namespace std;
int m, n;
bool *p;
int p_count = -1;
int getAnswer(int q) {
  cout << q << endl;
  fflush(stdout);
  int a;
  cin >> a;
  p_count++;
  p_count %= n;
  if (a == 0 || a == -2) exit(0);
  return a;
}
void searchAns(int l, int r) {
  int mid = (l + r) / 2;
  int ans = getAnswer(mid);
  ans = p[p_count] ? ans : -ans;
  if (ans == -1) {
    searchAns(l, mid - 1);
  } else {
    searchAns(mid + 1, r);
  }
}
int main() {
  cin >> m >> n;
  p = new bool[n];
  for (int i = 0; i < n; i++) {
    int ans = getAnswer(1);
    p[i] = ans == 1;
  }
  searchAns(1, m);
  return 0;
}
