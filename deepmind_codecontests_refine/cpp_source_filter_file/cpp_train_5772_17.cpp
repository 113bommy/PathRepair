#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool In[20010][11];
int C[20010];
int A[11];
void GetAll() {
  cin >> n >> m >> k;
  int buffer;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> buffer;
      if (buffer == 0) {
        In[i][j] = false;
      } else {
        In[i][j] = true;
      }
    }
  }
}
void Run() {
  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    A[b - 1]++;
    C[a - 1]++;
  }
  a = 0;
  for (int i = 0; i < n; i++) {
    a = 0;
    for (int j = 0; j < m; j++) {
      if (In[i][j]) {
        a += C[j];
      }
    }
    a -= C[i];
    cout << a << " ";
  }
}
int main() {
  GetAll();
  Run();
  return 0;
}
