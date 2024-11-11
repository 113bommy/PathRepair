#include <bits/stdc++.h>
struct Node {
  long long int sum, part;
};
std::vector<Node> drzewo;
int size, off, n, q;
long long int find(int sl, int sp, int ol = 1, int op = size / 2, int ind = 1,
                   long long int acc = 0) {
  if (ol == sl && op == sp)
    return acc * (ol - sl + 1) + drzewo[ind].sum;
  else {
    acc += drzewo[ind].part;
    int sr = (ol + op) / 2;
    if (sp <= sr)
      return find(sl, sp, ol, sr, ind * 2, acc);
    else if (sl > sr)
      return find(sl, sp, sr + 1, op, ind * 2 + 1, acc);
    else
      return find(sl, sr, ol, sr, ind * 2, acc) +
             find(sr + 1, sp, sr + 1, op, ind * 2 + 1, acc);
  }
}
void recalc(int ind, int length) {
  while (ind > 0) {
    length *= 2;
    drzewo[ind].sum = drzewo[2 * ind].sum + drzewo[2 * ind + 1].sum +
                      drzewo[ind].part * length;
    ind /= 2;
  }
}
void add(long long int value, int sl, int sp, int ol = 1, int op = size / 2,
         int ind = 1) {
  if (ol == sl && op == sp) {
    drzewo[ind].part += value;
    drzewo[ind].sum += value * (sp - sl + 1);
    recalc(ind / 2, sp - sl + 1);
  } else {
    int sr = (ol + op) / 2;
    if (sp <= sr) {
      add(value, sl, sp, ol, sr, ind * 2);
    } else if (sl > sr) {
      add(value, sl, sp, sr + 1, op, ind * 2 + 1);
    } else {
      add(value, sl, sr, ol, sr, ind * 2);
      add(value, sr + 1, sp, sr + 1, op, ind * 2 + 1);
    }
  }
}
std::set<int> zbior;
std::vector<int> k;
void construct() {
  for (int i = off; i > 0; i--) {
    drzewo[i].sum = drzewo[i * 2].sum + drzewo[i * 2 + 1].sum;
    drzewo[i].part = 0;
  }
}
void getval(int l1, int l2) { std::cout << find(l1, l2) << std::endl; }
void print() {
  for (int i = 1; i < n; i++) {
    std::cout << find(i, i) << " ";
  }
  std::cout << std::endl;
}
void printTree() {
  for (auto& i : drzewo) {
    std::cout << "(" << i.sum << " " << i.part << ") ";
  }
  std::cout << std::endl;
}
void make(int id, long long int value) {
  auto it = zbior.upper_bound(id);
  int tmp = id;
  while (true) {
    int next = *it;
    add(value, id, next - 1);
    int tmp = k[next - 1];
    long long int l, p;
    l = find(next - 1, next - 1);
    p = find(next, next);
    if (tmp + l > p) {
      value = tmp + l - p;
      id = next;
      auto itmp = it;
      it++;
      zbior.erase(itmp);
    } else
      break;
  }
  zbior.insert(tmp);
}
int main(void) {
  {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    n++;
    size = 1;
    while (size < 2 * n) size *= 2;
    drzewo.resize(size);
    off = size / 2 - 1;
    for (int i = 1; i < n; i++) std::cin >> drzewo[off + i].sum;
    drzewo[off + n].sum = LLONG_MAX / 2;
    k.resize(n);
    for (int i = 1; i < n - 1; i++) std::cin >> k[i];
    k[n - 1] = 0;
    std::cin >> q;
    for (int i = 1; i <= n; i++) zbior.insert(i);
    construct();
  }
  int a, b;
  char z;
  while (q--) {
    std::cin >> z >> a >> b;
    if (z == '+') {
      make(a, b);
    } else {
      std::cout << find(a, b) << "\n";
    }
  }
  return 0;
}
