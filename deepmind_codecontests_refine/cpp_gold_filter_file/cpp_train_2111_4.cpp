#include <bits/stdc++.h>
using namespace std;
void write_file(int n, int* arr, char* fname) {
  FILE* f = fopen(fname, "w");
  fprintf(f, "%d\n", n);
  for (int i = 0; i < 2 * n; ++i) {
    if (arr[i] == 0)
      fprintf(f, "%c\n", '+');
    else
      fprintf(f, "- %d\n", arr[i]);
  }
  fclose(f);
}
int* gen(int num) {
  int* arr = new int[2 * num]();
  int* pos = new int[num];
  srand(time(NULL));
  for (int i = 1; i <= num; ++i) {
    do {
      pos[i] = rand() % (2 * num);
    } while (arr[pos[i]] != 0);
    arr[pos[i]] = i;
  }
  delete[] pos;
  return arr;
}
int check_s(int num, int* arr) {
  std::stack<int> s;
  for (int i = 2 * num - 1; i >= 0; --i) {
    if (arr[i] > 0) {
      if (!s.empty() && s.top() < arr[i]) return 1;
      s.push(arr[i]);
    } else if (!s.empty()) {
      arr[i] = -s.top();
      s.pop();
    } else
      return 1;
  }
  return 0;
}
void print_arr(int num, int* arr, int mode = 1) {
  if (mode == 1) printf("%d\n", num);
  for (int i = 0; i < 2 * num; ++i) {
    if (mode == 1)
      if (arr[i] == 0)
        printf("+ ");
      else
        printf("-%d ", arr[i]);
    else if (mode == 2) {
      if (arr[i] < 0) {
        printf("+%d ", -arr[i]);
      } else {
        printf("-%d ", arr[i]);
      }
    } else if (mode == 3) {
      if (arr[i] < 0) {
        printf("%d ", -arr[i]);
      }
    }
  }
  printf("\n");
}
int* input(int* n) {
  cin >> *n;
  int* arr = new int[2 * *n];
  char c;
  for (int i = 0; i < 2 * *n; ++i) {
    cin >> c;
    if (c == '+') {
      arr[i] = 0;
    } else {
      int x;
      cin >> x;
      arr[i] = x;
    }
  }
  return arr;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int NUM;
  int* arr = input(&NUM);
  int res = check_s(NUM, arr);
  if (res == 0) {
    printf("YES\n");
    print_arr(NUM, arr, 3);
  } else {
    printf("NO\n");
  }
  delete[] arr;
  return 0;
}
