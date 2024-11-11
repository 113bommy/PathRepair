#include <bits/stdc++.h>
using namespace std;
int arr[1001];
map<int, bool> mp;
vector<int> an;
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    int coun = 0;
    int ans = 1;
    printf("YES\n");
    while (coun < n) {
      int flag = 1;
      for (int i = 0; i < n; i++) {
        if (mp[ans + arr[i]] == true) {
          flag = 2;
          for (int j = 0; i < i; j++) mp[ans + arr[j]] = false;
          break;
        }
        mp[ans + arr[i]] = true;
      }
      if (flag == 1) printf("%d ", ans), coun++;
      ans += 500;
    }
    mp.clear();
    printf("\n");
  }
}
