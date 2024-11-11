#include <bits/stdc++.h>
using namespace std;
struct T {
  T *l, *r;
  int v;
  int c;
  T(int v) : v(v), c(1) { l = r = NULL; }
  T(T *a) {
    l = a->l;
    r = a->r;
    v = a->v;
    c = a->c;
  }
  T() {}
};
T pool[(5000000) + 10000];
int stack_size;
T *my_new(char v) { return &(pool[stack_size++] = T(v)); }
T *my_new(T *a) { return &(pool[stack_size++] = T(a)); }
int count(T *c) {
  if (!c)
    return 0;
  else
    return c->c;
}
T *update(T *c) {
  if (!c) return c;
  c->c = count(c->l) + count(c->r) + 1;
  return c;
}
T *merge(T *a, T *b, int flag = 1) {
  if (!a) return b;
  if (!b) return a;
  if (rand() % (count(a) + count(b)) < count(a)) {
    T *R = flag ? my_new(a) : a;
    R->r = merge(a->r, b, flag);
    return update(R);
  } else {
    T *R = flag ? my_new(b) : b;
    R->l = merge(a, b->l, flag);
    return update(R);
  }
}
pair<T *, T *> split(T *c, int k, int flag = 1) {
  if (!c) return make_pair(c, c);
  T *R = flag ? my_new(c) : c;
  if (k <= count(c->l)) {
    pair<T *, T *> s = split(c->l, k, flag);
    R->l = s.second;
    return make_pair(s.first, update(R));
  } else {
    pair<T *, T *> s = split(c->r, k - count(c->l) - 1, flag);
    R->r = s.first;
    return make_pair(update(R), s.second);
  }
}
T *insert(T *c, int k, int value) {
  pair<T *, T *> div = split(c, k, 0);
  T *mono_tree = my_new(value);
  return merge(merge(div.first, mono_tree, 0), div.second, 0);
}
int tmp[1000001];
int tmp2[1000001];
int N, M, m;
pair<T *, T *> generate_tree() {
  stack_size = 0;
  T *root1 = NULL;
  T *root2 = NULL;
  for (int i = 0; i < N; i++) root1 = insert(root1, i, tmp[i]);
  for (int i = 0; i < N; i++) root2 = insert(root2, i, tmp2[i]);
  return make_pair(root1, root2);
}
void write(int *arr, T *c) {
  if (m >= N) return;
  if (!c) return;
  write(arr, c->l);
  if (m < N) arr[m++] = c->v;
  write(arr, c->r);
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp2[i]);
  }
  T *A, *B;
  pair<T *, T *> hoge = generate_tree();
  A = hoge.first;
  B = hoge.second;
  for (int i = 0; i < M; i++) {
    int a;
    int x, y, k;
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d%d%d", &x, &y, &k);
      x--, y--;
      pair<T *, T *> sub = split(A, x);
      pair<T *, T *> sub2 = split(sub.second, k);
      pair<T *, T *> sub3 = split(B, y);
      pair<T *, T *> sub4 = split(sub3.second, k);
      T *f1 = merge(sub3.first, sub2.first);
      T *f2 = merge(f1, sub3.second);
      B = f2;
      if (stack_size > (5000000)) {
        m = 0;
        write(tmp, A);
        m = 0;
        write(tmp2, B);
        pair<T *, T *> hoge = generate_tree();
        A = hoge.first;
        B = hoge.second;
      }
    } else {
      scanf("%d", &x);
      x--;
      pair<T *, T *> sub = split(B, x);
      pair<T *, T *> sub2 = split(sub.second, 1);
      printf("%d\n", sub2.first->v);
    }
  }
}
