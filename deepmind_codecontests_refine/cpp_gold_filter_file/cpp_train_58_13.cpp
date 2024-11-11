#include <bits/stdc++.h>
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::stack;
using std::string;
const double minlf = 1e-6;
const int maxd = 1e6;
const int inf = 1e9;
bool add(int* memory, int n, int name, int size) {
  int m = n - size + 1;
  for (int i = 0; i < m; i++) {
    bool enough_memory = true;
    for (int j = 0; j < size && enough_memory; j++) {
      if (memory[j + i]) enough_memory = false;
    }
    if (!enough_memory) continue;
    for (int j = 0; j < size; j++) {
      memory[j + i] = name;
    }
    return true;
  }
  return false;
}
bool remove(int* memory, int n, int name) {
  if (name <= 0) return false;
  int i;
  for (i = 0; i < n && memory[i] != name; i++) NULL;
  if (i == n) return false;
  for (int j = i; j < n && memory[j] == name; j++) {
    memory[j] = 0;
  }
  return true;
}
void defragment(int* memory, int n) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    memory[j] = memory[i];
    if (!memory[i]) continue;
    if (i >= ++j) memory[i] = 0;
  }
}
int main() {
  int m, n, t;
  char s[20];
  scanf("%d%d", &m, &n);
  int* memory = new int[n];
  memset(memory, 0, sizeof(int) * n);
  int name = 1;
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    if (s[0] == 'a') {
      scanf("%d", &t);
      if (add(memory, n, name, t)) {
        printf("%d\n", name++);
      } else {
        printf("NULL\n");
      }
    } else if (s[0] == 'e') {
      scanf("%d", &t);
      if (!remove(memory, n, t)) {
        printf("ILLEGAL_ERASE_ARGUMENT\n");
      }
    } else {
      defragment(memory, n);
    }
  }
  return 0;
}
