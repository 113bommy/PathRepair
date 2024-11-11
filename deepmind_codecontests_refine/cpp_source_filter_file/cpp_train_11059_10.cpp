#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  scanf("%d", &test);
  for (int i = 0; i < test; i++) {
    vector<int> v1;
    char arr[2 * 100000];
    scanf("%s", arr);
    v1.push_back(0);
    int j = 1, cnt = 1;
    while (arr[j] != '\0') {
      if (arr[j] == 'R') {
        v1.push_back(j);
        cnt++;
      }
      j++;
    }
    v1.push_back(j);
    cnt++;
    int diff = 0;
    for (int k = 0; k < (cnt - 1); k++) {
      if ((v1[k + 1] - v1[k]) > diff) {
        diff = v1[k + 1] - v1[k];
      }
    }
    printf("%d\n", diff);
  }
}
