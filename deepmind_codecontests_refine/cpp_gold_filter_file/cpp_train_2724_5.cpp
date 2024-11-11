#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  long int sum;
  struct node *left, *right;
  struct node* next;
};
struct node* newNode(int data) {
  struct node* Node = new (struct node);
  Node->data = data;
  Node->left = Node->right = Node->next = NULL;
  return (Node);
}
long long ans[110][110][2];
void solveTestCase() {
  int n1, n2, k1, k2;
  scanf("%d", &n1);
  ;
  scanf("%d", &n2);
  ;
  scanf("%d", &k1);
  ;
  scanf("%d", &k2);
  ;
  k1 = min(k1, n1);
  k2 = min(k2, n2);
  ans[0][0][0] = 1;
  ans[0][0][1] = 1;
  for (int i = 0; i < n1 + 1; i++) {
    for (int j = 0; j < n2 + 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      for (int k = 1; k < k1 + 1; k++) {
        if (i - k < 0) {
          break;
        }
        ans[i][j][0] = (ans[i][j][0] + ans[i - k][j][1]) % 100000000;
      }
      for (int k = 1; k < k2 + 1; k++) {
        if (j - k < 0) {
          break;
        }
        ans[i][j][1] = (ans[i][j][1] + ans[i][j - k][0]) % 100000000;
      }
    }
  }
  long long ans_final = (ans[n1][n2][0] + ans[n1][n2][1]) % 100000000;
  printf("%I64d\n", ans_final);
  ;
}
int main() {
  solveTestCase();
  return 0;
}
