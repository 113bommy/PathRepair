#include <bits/stdc++.h>
using namespace std;
int main() {
  int(n), (k);
  scanf("%d%d", &(n), &(k));
  int(p);
  scanf("%d", &(p));
  vector<int> odd;
  vector<int> even;
  int ip[n];
  for (int(i) = 0; (i) < (n); (i)++) {
    scanf("%d", &ip[i]);
    if (ip[i] % 2 == 0)
      even.push_back(ip[i]);
    else
      odd.push_back(ip[i]);
  }
  if ((odd.size() >= (k - p)) && (odd.size() - (k - p)) % 2 == 0 &&
      ((odd.size() - (k - p)) / 2 + even.size() >= p)) {
    printf("YES\n");
    if (odd.size() == k - p) {
      if (p != 0) {
        for (int(i) = 0; (i) < (odd.size()); (i)++)
          printf("%d %d\n", 1, odd[i]);
      }
      if (p == 0) {
        int i;
        for (i = 0; i < odd.size() - 1; i++) printf("%d %d\n", 1, odd[i]);
        printf("%d ", even.size() + 1);
        printf("%d ", odd[odd.size() - 1]);
        for (int(j) = 0; (j) < (even.size()); (j)++) printf("%d ", even[j]);
      }
      if (p != 0) {
        int i = 0;
        for (i = 0; i < p - 1; i++) printf("%d %d\n", 1, even[i]);
        printf("%d ", even.size() + 1 - p);
        for (i = p - 1; i < even.size(); i++) {
          printf("%d ", even[i]);
        }
      }
    } else {
      int yo = p;
      int i = 0;
      if (p != 0) {
        for (i = 0; i < k - p; i++) printf("%d %d\n", 1, odd[i]);
      } else {
        int i;
        for (i = 0; i < k - 1; i++) printf("%d %d\n", 1, odd[i]);
        printf("%d ", odd.size() + even.size() + 1 - k);
        for (i = k - 1; i < odd.size(); i++) printf("%d ", odd[i]);
        for (i = 0; i < even.size(); i++) printf("%d ", even[i]);
      }
      if (p != 0) {
        int brk = 0;
        int bb = 0;
        for (i = k - p; i < odd.size(); i = i + 2) {
          if (yo == 1) {
            brk = i;
            bb = 1;
            break;
          }
          printf("%d %d %d\n", 2, odd[i], odd[i + 1]);
          yo--;
        }
        if (bb != 0) {
          printf("%d ", odd.size() + even.size() - brk);
          for (int i = brk; i < odd.size(); i++) printf("%d ", odd[i]);
          for (int i = 0; i < even.size(); i++) {
            printf("%d ", even[i]);
          }
        } else {
          for (int i = 0; i < yo - 1; i++) printf("%d %d\n", 1, even[i]);
          printf("%d ", even.size() + 1 - yo);
          for (int i = yo - 1; i < even.size(); i++) printf("%d ", even[i]);
        }
      }
    }
  } else {
    printf("NO");
  }
  return 0;
}
