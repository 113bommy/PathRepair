#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int id, num;
} man[110];
bool cmp(node a, node b) {
  if (a.num == b.num) {
    return a.id < b.id;
  }
  return a.num > b.num;
}
int main() {
  int sum = 0, j;
  cin.sync_with_stdio(false);
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      man[i].id = i + 1;
      cin >> man[i].num;
      sum += man[i].num;
    }
    if (sum < n - 1) {
      cout << -1 << endl;
      continue;
    }
    if (man[0].num == 0) {
      cout << -1 << endl;
      continue;
    }
    cout << n - 1 << endl;
    sort(man + 1, man + n, cmp);
    for (j = 1; j < n && j <= man[0].num; j++) {
      cout << 1 << " " << man[j].id << endl;
      ;
    }
    for (int i = 1; j < n; i++) {
      for (int k = 0; j < n && k < man[i].num; k++) {
        cout << man[i].id << " " << man[j].id << endl;
        j++;
      }
    }
  }
  return 0;
}
