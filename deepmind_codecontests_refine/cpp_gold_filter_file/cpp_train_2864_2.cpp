#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 2e5;
vector<int> g[N];
int a[N], b[N], R[N], L[N];
struct Stack {
  int top;
  int items[200004];
};
void push(struct Stack *ps, int x) {
  if (ps->top == 200004 - 1) {
    printf("Error: Stack overflow\n");
    getchar();
    exit(0);
  } else {
    ps->top += 1;
    int top = ps->top;
    ps->items[top] = x;
  }
}
bool isEmpty(struct Stack *ps) { return (ps->top == -1) ? true : false; }
int pop(struct Stack *ps) {
  int temp;
  if (ps->top == -1) {
    printf("Error: Stack underflow \n");
    getchar();
    exit(0);
  } else {
    int top = ps->top;
    temp = ps->items[top];
    ps->top -= 1;
    return temp;
  }
}
void go(int arr[], int n) {
  int i = 0;
  struct Stack s;
  s.top = -1;
  int element, next;
  push(&s, 0);
  for (i = 1; i < n; i++) {
    next = i;
    if (isEmpty(&s) == false) {
      element = pop(&s);
      while (arr[element] < arr[next]) {
        R[element] = next - element;
        if (isEmpty(&s) == true) break;
        element = pop(&s);
      }
      if (arr[element] >= arr[next]) push(&s, element);
    }
    push(&s, next);
  }
  while (isEmpty(&s) == false) {
    element = pop(&s);
    next = 0;
    R[element] = n - element;
  }
}
void go1(int arr[], int n) {
  int i = 0;
  struct Stack s;
  s.top = -1;
  int element, next;
  push(&s, 0);
  for (i = 1; i < n; i++) {
    next = i;
    if (isEmpty(&s) == false) {
      element = pop(&s);
      while (arr[element] <= arr[next]) {
        L[element] = next - element;
        if (isEmpty(&s) == true) break;
        element = pop(&s);
      }
      if (arr[element] > arr[next]) push(&s, element);
    }
    push(&s, next);
  }
  while (isEmpty(&s) == false) {
    element = pop(&s);
    next = 0;
    L[element] = n - element;
  }
}
int main() {
  int i, n, l, r, q;
  cin >> n >> q;
  for (i = 0; i < n; i++) cin >> a[i];
  while (q--) {
    cin >> l >> r;
    l--, r--;
    for (i = l; i < r; i++) b[i - l] = abs(a[i] - a[i + 1]);
    int len = r - l;
    go(b, r - l);
    for (i = 0; i < (r - l) / 2; i++) swap(b[i], b[r - l - i - 1]);
    go1(b, r - l);
    for (i = 0; i < (r - l) / 2; i++) swap(L[i], L[r - l - i - 1]);
    long long ans = 0;
    for (i = 0; i < r - l; i++)
      ans += (L[i] * 1LL * R[i]) * abs(a[i + l] - a[i + l + 1]);
    cout << ans << endl;
  }
  return 0;
}
