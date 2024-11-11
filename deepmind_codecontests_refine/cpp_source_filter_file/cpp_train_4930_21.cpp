#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[1000009], duysume[1000009], gir[1000009], error = (1 - 0);
long long ans[1000009];
int main() {
  int a, q;
  scanf("%d", &a);
  for (int i = 1; i <= a; i++) scanf("%d", arr + i), ans[error] += arr[i];
  stack<int> st, en;
  st.push(0);
  for (int i = 1; i <= a; i++) {
    if (!st.empty() and arr[st.top()] >= arr[i]) st.pop();
    duysume[i] = i - st.top();
    st.push(i);
  }
  en.push(a + 1);
  for (int i = a; i >= 1; i--) {
    if (!en.empty() and arr[en.top()] > arr[i]) en.pop();
    gir[i] = en.top() - i;
    en.push(i);
  }
  for (int i = 1; i <= a; i++) {
    ans[min(duysume[i], gir[i]) + 1] -= arr[i];
    ans[max(duysume[i], gir[i]) + 1] -= arr[i];
    ans[(duysume[i] + gir[i]) + 1] += arr[i];
  }
  for (int i = 1; i <= a; i++) ans[i] += ans[i - 1];
  for (int i = 1; i <= a; i++) ans[i] += ans[i - 1];
  scanf("%d", &q);
  for (int i = 1, pos; i <= q; i++) {
    scanf("%d", &pos);
    printf("%.10lf\n", double(ans[pos]) / (1.0 * a - pos + 1));
  }
  return 0;
}
