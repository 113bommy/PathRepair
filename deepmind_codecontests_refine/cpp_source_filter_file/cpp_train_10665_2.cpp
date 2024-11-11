#include <bits/stdc++.h>
using namespace std;
int n;
int k;
struct st {
  st *a[27];
  bool dp;
  bool ldp;
  st() {
    for (int i = 0; i < 27; i++) {
      a[i] = NULL;
    }
    dp = false;
    ldp = false;
  }
};
st *root;
void add(string s) {
  st *b = root;
  for (int i = 0; i < s.size(); i++) {
    int nex = s[i] - 'a';
    if (b->a[nex] == NULL) {
      b->a[nex] = new st();
    }
    b = b->a[nex];
  }
}
inline bool dfs(st *b) {
  bool ok = false;
  for (int i = 0; i < 26; i++) {
    if (b->a[i] == NULL) {
      continue;
    }
    ok = true;
    b->dp |= dfs(b->a[i]) ^ 1;
    b->ldp |= b->a[i]->ldp;
  }
  b->ldp |= ok ^ true;
  return b->dp;
}
int a[] = {0, 0};
int main() {
  scanf("%d%d", &n, &k);
  root = new st();
  string kk;
  while (n--) {
    cin >> kk;
    add(kk);
  }
  bool res = dfs(root);
  if (root->dp && root->ldp) {
    puts("First");
    return 0;
  }
  if (root->dp) {
    if (k % 2) {
      puts("First");
    } else {
      puts("Second");
    }
  } else {
    puts("Second");
    return 0;
  }
  return 0;
  if (res == true) {
    a[1] = 1;
  } else {
    a[0] = a[1] = 1;
  }
  int num = a[(k % 2) ^ 1];
  if (num == 0) {
    puts("First");
  } else {
    puts("Second");
  }
  return 0;
}
