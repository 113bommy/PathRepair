#include <bits/stdc++.h>
using namespace std;
void debugarr(int* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
int testnum;
int ar[2004];
int n, b;
int q;
int mins = 1000000;
int temp, posmin, postemp, res;
void solve() {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      res = ((res) > ((b / ar[i] * ar[j]) + b % ar[i])
                 ? (res)
                 : ((b / ar[i] * ar[j]) + b % ar[i]));
  printf("%d", res);
}
bool input() {
  scanf("%d", &n);
  scanf("%d", &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  return true;
}
int main() {
  int T = 1;
  for (testnum = 1; testnum <= T; testnum++) {
    if (!input()) break;
    solve();
  }
}
