#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100010];
bool isprime[100010];
bool geh[100010];
set<int> seet;
set<int>::iterator it;
int bta3men[100010];
void sevie() {
  isprime[1] = 1;
  isprime[0] = 1;
  for (int i = 2; i <= 100000; ++i) {
    if (!isprime[i]) {
      arr[i].push_back(i);
      for (int j = i * 2; j <= 100000; j += i) {
        isprime[j] = 1;
        arr[j].push_back(i);
      }
    }
  }
}
int main() {
  sevie();
  int n, m, x;
  char c;
  scanf("%d", &n);
  scanf("%d", &m);
  while (m--) {
    cin >> c;
    scanf("%d", &x);
    if (c == '+') {
      if (geh[x])
        printf("Already on\n");
      else {
        bool flag = false;
        int temp = seet.size();
        for (int i = 0; i < arr[x].size(); ++i) {
          it = seet.find(arr[x][i]);
          if (it != seet.end()) {
            printf("Conflict with ");
            printf("%d\n", bta3men[*it]);
            flag = true;
            break;
          }
        }
        if (!flag) {
          for (int i = 0; i < arr[x].size(); ++i) {
            seet.insert(arr[x][i]);
            bta3men[arr[x][i]] = x;
          }
          geh[x] = 1;
          printf("Success\n");
        }
      }
    } else {
      if (!geh[x])
        printf("Already off\n");
      else {
        for (int i = 0; i < arr[x].size(); ++i) {
          it = seet.find(arr[x][i]);
          bta3men[*it] = 0;
          seet.erase(it);
        }
        geh[x] = 0;
        printf("Success\n");
      }
    }
  }
  return 0;
}
