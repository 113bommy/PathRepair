#include <bits/stdc++.h>
using namespace std;
const long long M = 300005;
int n;
long long int a[M] = {0};
long long int k[M] = {0};
int flag = 0;
struct Node {
  int endCount = 0;
  long long int number = 0;
  Node *left, *right, *parent;
  Node(Node *p) {
    parent = p;
    number = 0;
    endCount = 0;
    left = NULL;
    right = NULL;
  }
};
bool getBit(long long int x, int k) { return (x & (1 << k)) > 0; }
void insert(Node *head, long long int x) {
  Node *p = head;
  head->endCount++;
  for (int i = 30; i >= 1; i--) {
    bool bit = getBit(x, i);
    if (!bit) {
      if (!p->left) {
        p->left = new Node(p);
      }
      p = p->left;
    } else {
      if (!p->right) {
        p->right = new Node(p);
      }
      p = p->right;
    }
    p->endCount++;
  }
  p->number = x;
}
long long int search(Node *head, long long int x) {
  Node *p = head;
  p->endCount--;
  for (int i = 29; i >= 0; i--) {
    bool bit = getBit(x, i);
    if (!bit) {
      if (!p->left) {
        p = p->right;
      } else {
        p = p->left;
      }
    } else {
      if (!p->right) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
    if (flag == 1 && i == 1) {
    }
    p->endCount--;
  }
  long long int ans = p->number;
  for (int i = 0; i <= 29; i++) {
    bool bit = getBit(x, i);
    if (!bit) {
      if (p->endCount == 0) {
        p = p->parent;
        p->left = NULL;
      } else {
        break;
      }
    } else {
      if (p->endCount == 0) {
        p = p->parent;
        p->right = NULL;
      } else {
        break;
      }
    }
  }
  return ans;
}
int main() {
  long long int a1 = 584777693;
  long long int a2 = 584776441;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  Node *head = new Node(NULL);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &k[i]);
    insert(head, k[i]);
  }
  for (int i = 0; i < n; i++) {
    if (n == 300000 && i == 4296) {
      flag = 1;
    }
    long long int ans = search(head, a[i]);
    if (flag == 1) {
    }
    printf("%lld ", ans ^ a[i]);
  }
  return 0;
}
