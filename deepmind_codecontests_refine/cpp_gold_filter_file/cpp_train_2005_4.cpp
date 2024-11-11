#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];
vector<int> arr;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    string a, b;
    cin >> a >> b;
    vector<int> arr;
    arr.clear();
    char pre = a[0];
    for (int i = 1; i < n; i++) {
      if (pre == a[i]) continue;
      pre = a[i];
      arr.push_back(i);
    }
    char now = pre;
    for (int i = n - 1; i >= 0; i--)
      if (now != b[i]) {
        now = b[i];
        arr.push_back(i + 1);
      }
    printf("%d ", arr.size());
    for (int i = 0; i < arr.size(); i++) printf("%d ", arr[i]);
    puts("");
  }
  return 0;
}
