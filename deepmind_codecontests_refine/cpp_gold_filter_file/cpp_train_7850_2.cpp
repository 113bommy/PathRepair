#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
bool a[maxn][maxn];
void addEdge(int i, int j) { a[i][j] = a[j][i] = true; }
int main() {
  int n;
  vector<int> v;
  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof(a));
    v.clear();
    while (n) {
      v.push_back(n % 2);
      n /= 2;
    }
    int temp = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i]) {
        temp = i;
        break;
      }
    }
    addEdge(1, 3);
    addEdge(1, 4);
    int num1, num2;
    num1 = num2 = 3;
    for (int i = 2; i < temp + 2; i++) {
      for (int j = 0; j < i; j++) {
        addEdge(num1 + j, num1 + j + i);
        addEdge(num1 + j, num1 + i + i);
      }
      num1 += i;
      num2 = num1;
    }
    for (int i = 0; i <= temp; i++) {
      if (v[i]) {
        addEdge(num2 + i + 1, 2);
      }
    }
    printf("%d\n", num2 + temp + 1);
    for (int i = 1; i <= num2 + temp + 1; i++) {
      for (int j = 1; j <= num2 + temp + 1; j++) {
        if (a[i][j]) {
          printf("Y");
        } else {
          printf("N");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
