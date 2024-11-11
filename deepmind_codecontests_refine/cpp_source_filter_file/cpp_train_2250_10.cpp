#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;
typedef struct Target {
  int x;
  int r;
  int id;
  int num;
} Target;
Target tar[MAXN];
bool cmp1(Target a, Target b) { return a.x < b.x; }
bool cmp2(Target a, Target b) { return a.num < b.num; }
int BinarySearch(int low, int high, int num) {
  high = high - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (num > tar[mid].r) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}
int main() {
  int n, m;
  int x, y;
  int flag;
  int count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tar[i].x >> tar[i].r;
    tar[i].id = -1;
    tar[i].num = i;
  }
  sort(tar, tar + n, cmp1);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    flag = BinarySearch(0, n, x);
    for (int j = flag - 4; j <= flag + 4; j++) {
      if (j >= 0 && j < n) {
        if (tar[j].id == -1 &&
            (tar[j].x - x) * (tar[j].x - x) + y * y <= tar[j].r * tar[j].r) {
          tar[j].id = i;
          count++;
        }
      }
    }
  }
  sort(tar, tar + n, cmp2);
  cout << count << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << tar[i].id << " ";
  }
  cout << tar[n - 1].id << endl;
  return 0;
}
