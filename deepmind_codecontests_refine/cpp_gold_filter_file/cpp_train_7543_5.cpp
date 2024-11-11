#include <bits/stdc++.h>
using namespace std;
const bool testing = false;
int v[100005];
map<int, int> l;
map<int, int> r;
void getsides(int& a, int& b, int lst0, int n) {
  l.clear();
  for (int i = lst0 + 1; i < n - lst0 - 1; i++) {
    l[v[i]]++;
  }
  a = 0;
  r.clear();
  while (true) {
    if (++r[v[lst0 + a + 1]] > l[v[lst0 + a + 1]] / 2) {
      break;
    }
    a++;
  }
  b = 0;
  r.clear();
  while (true) {
    if (++r[v[n - lst0 - b - 2]] > l[v[n - lst0 - b - 2]] / 2) {
      break;
    }
    b++;
  }
}
void program() {
  l.clear();
  r.clear();
  int n;
  int fst1 = -1;
  int lst1 = -1;
  int lst0 = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
  }
  int h = (n + 1) / 2;
  for (int i = 0; i < h; i++) {
    int g = n - i - 1;
    if (v[i] != v[g]) {
      auto p = r.find(v[i]);
      if (p == r.end()) {
        l[v[i]]++;
      } else {
        if (--p->second == 0) {
          r.erase(p);
        }
      }
      p = l.find(v[g]);
      if (p == l.end()) {
        r[v[g]]++;
      } else {
        if (--p->second == 0) {
          l.erase(p);
        }
      }
    }
    if (l.size() == 0 && r.size() == 0) {
      lst0 = i;
    } else {
      if (fst1 == -1) fst1 = i;
      lst1 = i;
    }
  }
  for (map<int, int>::const_iterator i = l.cbegin(); i != l.cend(); i++) {
    r[i->first] += i->second;
  }
  bool isodd = n % 2;
  if (isodd) r[v[h - 1]]++;
  for (map<int, int>::const_iterator i = r.cbegin(); i != r.cend(); i++) {
    if (i->second % 2) {
      if (isodd)
        isodd = false;
      else {
        cout << "0" << endl;
        return;
      }
    }
  }
  if (fst1 == -1) {
    long long r = n;
    r *= n + 1;
    r /= 2;
    cout << r << endl;
    return;
  } else {
    if (lst1 == h - 1) {
      int x, y;
      getsides(x, y, lst0, n);
      long long r = lst0 + 2 + y;
      r *= fst1 + 1;
      long long a = fst1 + 1;
      a *= lst0 + 2 + x - fst1 - 1;
      r += a;
      cout << r << endl;
    } else {
      long long r = fst1 + 1;
      r *= n - lst1 - 1;
      long long a = fst1 + 1;
      a *= n - lst1 - 1 - fst1 - 1;
      r += a;
      cout << r << endl;
    }
  }
}
int main() {
  if (!testing) {
    program();
    return 0;
  }
  FILE* fin = NULL;
  fin = fopen("in.txt", "w+");
  fprintf(fin, "6\n	3 6 5 3 3 5	\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(4) => expected : \n");
  printf("0\n");
  printf("test case(4) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "3\n2 2 2\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(1) => expected : \n");
  printf("6\n");
  printf("test case(1) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "6\n3 6 5 3 3 5\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(2) => expected : \n");
  printf("0\n");
  printf("test case(2) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "5\n5 5 2 5 2\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(3) => expected : \n");
  printf("4\n");
  printf("test case(3) => founded  : \n");
  program();
  fin = fopen("in.txt", "w+");
  fprintf(fin, "7\n1 3 5 2 5 3 1\n");
  fclose(fin);
  freopen("in.txt", "r", stdin);
  printf("test case(5) => expected : \n");
  printf("?\n");
  printf("test case(5) => founded  : \n");
  program();
  return 0;
}
