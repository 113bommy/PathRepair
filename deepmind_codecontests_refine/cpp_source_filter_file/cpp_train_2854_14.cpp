#include <bits/stdc++.h>
using namespace std;
FILE* _fin = stdin;
FILE* _fout = stdout;
int _min(int a, int b) { return a <= b ? a : b; }
int _min(long long a, long long b) { return a <= b ? a : b; }
int _max(int a, int b) { return a >= b ? a : b; }
int _max(long long a, long long b) { return a >= b ? a : b; }
void zero(int* data, int n) { memset(data, 0, sizeof(int) * n); }
void zero(long long* data, int n) { memset(data, 0, sizeof(long long) * n); }
void zero(char* data, int n) { memset(data, 0, sizeof(char) * n); }
char readc() {
  char var;
  fscanf(_fin, "%c", &var);
  return var;
}
int readi() {
  int var;
  fscanf(_fin, "%d", &var);
  return var;
}
double readlf() {
  double var;
  fscanf(_fin, "%lf", &var);
  return var;
}
long long readll() {
  long long var;
  fscanf(_fin, "%lld", &var);
  return var;
}
void repread(int* data, int n) {
  for (int i = 0; i < n; ++i) data[i] = readi();
}
void repread(long long* data, int n) {
  for (int i = 0; i < n; ++i) data[i] = readll();
}
int reads(char* str, int maxsize) {
  for (;;) {
    if (fgets(str, maxsize, _fin) == NULL) break;
    if (str[0] != '\n' && str[0] != '\r') break;
  }
  int slen = strlen(str);
  if (slen == 0) return 0;
  if (str[slen - 1] == '\n' || str[slen - 1] == '\r') str[--slen] = 0;
  return slen;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  return (a / g) * b;
}
void reverse(char* data, int n) {
  int k = n >> 1;
  for (int i = 0; i < k; ++i) {
    char tmp = data[i];
    data[i] = data[n - i - 1];
    data[n - i - 1] = tmp;
  }
}
void reverse(int* data, int n) {
  int k = n >> 1;
  for (int i = 0; i < k; ++i) {
    int tmp = data[i];
    data[i] = data[n - i - 1];
    data[n - i - 1] = tmp;
  }
}
struct Veci {
  int* data;
  int size;
  int n;
};
void init(Veci* t, int size) {
  t->data = (int*)malloc(sizeof(int) * size);
  t->size = size;
  t->n = 0;
}
void resize(Veci* t) {
  int ns = t->size * 1.2f;
  t->data = (int*)realloc(t->data, sizeof(int) * ns);
  t->size = ns;
}
void add(Veci* t, int val) {
  if (t->n >= t->size) resize(t);
  int k = t->n;
  t->data[k] = val;
  t->n = k + 1;
}
void free(Veci* t) { free(t->data); }
struct Vecll {
  long long* data;
  int size;
  int n;
};
void init(Vecll* t, int size) {
  t->data = (long long*)malloc(sizeof(long long) * size);
  t->size = size;
  t->n = 0;
}
void resize(Vecll* t) {
  int ns = t->size * 1.2f;
  t->data = (long long*)realloc(t->data, sizeof(long long) * ns);
  t->size = ns;
}
void add(Vecll* t, long long val) {
  if (t->n >= t->size) resize(t);
  int k = t->n;
  t->data[k] = val;
  t->n = k + 1;
}
void free(Vecll* t) { free(t->data); }
struct Vecs {
  char** data;
  int size;
  int n;
};
void init(Vecs* t, int size) {
  t->data = (char**)malloc(sizeof(char*) * size);
  t->size = size;
  t->n = 0;
}
void resize(Vecs* t) {
  int ns = t->size * 1.2f;
  t->data = (char**)realloc(t->data, sizeof(char*) * ns);
  t->size = ns;
}
void add(Vecs* t, char* val) {
  if (t->n >= t->size) resize(t);
  int k = t->n;
  t->data[k] = val;
  t->n = k + 1;
}
void free(Vecs* t) { free(t->data); }
int ispali(int* a, int* b, int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[n - i - 1]) {
      return 0;
    }
  }
  return 1;
}
int ispalc(char* a, char* b, int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[n - i - 1]) {
      return 0;
    }
  }
  return 1;
}
struct Pairi {
  int x, y;
};
int cmp_Pairi(const void* _a, const void* _b) {
  Pairi* a = (Pairi*)_a;
  Pairi* b = (Pairi*)_b;
  if (a->x < b->x)
    return -1;
  else {
    if (a->x == b->x) {
      if (a->y == b->y) return 0;
      if (a->y < b->y)
        return -1;
      else
        return 1;
    } else {
      return 1;
    }
  }
}
void sort_Pairi(Pairi* d, int n) { qsort(d, n, sizeof(Pairi), cmp_Pairi); }
int cmp_Str(const void* _a, const void* _b) {
  char* a = *((char**)_a);
  char* b = *((char**)_b);
  return strcmp(a, b);
}
void sort_Str(char** str, int n) { qsort(str, n, sizeof(char*), cmp_Str); }
long long expmod(long long x, long long n, long long m) {
  long long ans = 1;
  for (; n;) {
    if (n & 1) ans = (ans * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return ans;
}
long long combmod(long long n, long long k, long long m) {
  long long ret = 1;
  long long div = 1;
  for (long long i = 0; i < k; ++i) {
    ret = (ret * (n - i) % m) % m;
    div = (div * (i + 1)) % m;
  }
  div = expmod(div, m - 2, m) % m;
  return (ret * div) % m;
}
int next_perm(int* data, int n) {
  int rootidx = -1;
  for (int i = n - 2; i >= 0; --i) {
    if (data[i] < data[i + 1]) {
      rootidx = i;
      break;
    }
  }
  if (rootidx == -1) return 0;
  int ceilingidx = rootidx + 1;
  for (int i = rootidx + 2; i < n; ++i) {
    if (data[i] > data[rootidx] && data[i] < data[ceilingidx]) {
      ceilingidx = i;
    }
  }
  {
    int t = data[rootidx];
    data[rootidx] = data[ceilingidx];
    data[ceilingidx] = t;
  };
  std::sort(&data[rootidx + 1], &data[rootidx + 1] + n - rootidx - 1);
  return 1;
}
int count_digits(long long a) {
  int k = 0;
  for (;;) {
    if (a == 0) break;
    k++;
    a /= 10;
  }
  return k;
}
int bs_exists(int* data, int n, int val) {
  int left = 0;
  int right = n - 1;
  for (; left < right;) {
    int mid = (left + right + 1) >> 1;
    if (data[mid] <= val)
      left = mid;
    else
      right = mid - 1;
  }
  return right;
}
int main() {
  {
    _fin = fopen("input.txt", "r");
    if (_fin == NULL) _fin = stdin;
  };
  int n = readi();
  static int a[100001];
  repread(a, n);
  if (n == 1) {
    fprintf(_fout, "%d\n", 1);
    return 0;
  }
  int best = 2;
  int len = 2;
  for (int i = 2; i < n; ++i) {
    if (a[i - 2] + a[i - 1] == a[i]) {
      len++;
      if (len > best) best = len;
    } else {
      len = 0;
    }
  }
  fprintf(_fout, "%d\n", best);
  return 0;
}
