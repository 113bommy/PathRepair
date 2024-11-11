#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
bool vis[100005];
int conflict[100005];
bool isPrime[100005];
void sieve() {
  int x = 100000;
  isPrime[0] = isPrime[1] = true;
  for (int i = 2; i <= 100000; i++) {
    if (!isPrime[i]) {
      for (int j = 2 * i; j <= 100000; j += i) {
        isPrime[j] = true;
        v[j].push_back(i);
      }
    }
  }
}
int main() {
  sieve();
  int n, m;
  cin >> n >> m;
  char c;
  int x;
  while (m--) {
    scanf(" %c", &c);
    scanf("%d", &x);
    if (c == '+') {
      if (vis[x]) {
        printf("Already on\n");
        continue;
      }
      bool flag = false;
      for (int i = 0; i < v[x].size(); i++) {
        if (vis[conflict[v[x][i]]]) {
          flag = true;
          printf("Conflict with %d\n", conflict[v[x][i]]);
          break;
        }
      }
      if (!flag) {
        printf("Success\n");
        vis[x] = true;
        for (int i = 0; i < v[x].size(); i++) {
          conflict[v[x][i]] = x;
        }
      }
    } else {
      if (!vis[x]) {
        printf("Already off\n");
        continue;
      }
      for (int i = 0; i < v[x].size(); i++) {
        conflict[v[x][i]] = 0;
      }
      vis[x] = false;
      printf("Success\n");
    }
  }
  return 0;
}
