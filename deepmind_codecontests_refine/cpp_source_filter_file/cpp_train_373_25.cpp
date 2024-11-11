#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")
struct node {
  int key;
  int prior;
  node* left;
  node* right;
  long long m[5];
  int cnt;
  node() {}
  node(int kkey, int pprior) {
    key = kkey;
    prior = pprior;
    left = NULL;
    right = NULL;
    cnt = 1;
    memset(m, 0, sizeof(m));
    m[0] = key;
  }
};
long long get_med(node*& t, int i) {
  if (t == NULL) return 0;
  return t->m[i];
}
int cnt(node*& t) {
  if (t == NULL) return 0;
  return t->cnt;
}
void upd_cnt(node*& t) {
  if (t == NULL) return;
  t->cnt = cnt(t->left) + cnt(t->right) + 1;
}
void upd_med(node*& t) {
  if (t == NULL) return;
  for (int i = 0; i < 5; ++i) {
    t->m[i] =
        get_med(t->left, i) + get_med(t->right, (4 - cnt(t->left) + i) % 5);
  }
  t->m[cnt(t->left) % 5] += t->key;
}
void split(node* t, int x, node*& left, node*& right) {
  if (t == NULL) {
    left = NULL;
    right = NULL;
  } else if (t->key > x) {
    split(t->left, x, left, t->left);
    right = t;
  } else {
    split(t->right, x, t->right, right);
    left = t;
  }
  upd_cnt(t);
  upd_med(t);
}
void merge(node* left, node* right, node*& t) {
  if (left == NULL) {
    t = right;
  } else if (right == NULL) {
    t = left;
  } else if (left->prior > right->prior) {
    merge(left->right, right, left->right);
    t = left;
  } else {
    merge(left, right->left, right->left);
    t = right;
  }
  upd_cnt(t);
  upd_med(t);
}
void add(node*& t, node* n) {
  if (t == NULL) {
    t = n;
  } else if (t->prior < n->prior) {
    split(t, n->key, n->left, n->right);
    t = n;
  } else if (n->key < t->key) {
    add(t->left, n);
  } else {
    add(t->right, n);
  }
  upd_cnt(t);
  upd_med(t);
}
void del(node*& t, int key) {
  if (t->key == key) {
    merge(t->left, t->right, t);
  } else if (key < t->key) {
    del(t->left, key);
  } else {
    del(t->right, key);
  }
  upd_cnt(t);
  upd_med(t);
}
node* Tree = NULL;
int main() {
  char s[10];
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    int x;
    scanf("%s", s);
    if (strcmp(s, "add") == 0) {
      scanf("%d", &x);
      node* tt = new node(x, rand());
      add(Tree, tt);
    } else if (strcmp(s, "del") == 0) {
      scanf("%d", &x);
      del(Tree, x);
    } else {
      printf("%I64d\n", get_med(Tree, 2));
    }
  }
  return 0;
}
