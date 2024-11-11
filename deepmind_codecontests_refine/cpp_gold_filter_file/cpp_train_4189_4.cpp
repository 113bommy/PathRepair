#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  while (cin >> t) {
    for (int i = 0; i < t; ++i) {
      int n;
      cin >> n;
      bool a[n - 1];
      for (int i = 0; i < n - 1; ++i) {
        char aa;
        cin >> aa;
        if (aa == '<')
          a[i] = true;
        else
          a[i] = false;
      }
      int b[n];
      for (int i = 0; i < n; ++i) b[i] = n - 1 - i;
      int count = 0;
      for (int i = 0; i < n - 1; ++i) {
        if (a[i])
          ++count;
        else if (count > 0) {
          int c[count + 1];
          for (int j = 0; j < count + 1; ++j) c[j] = b[i - j];
          for (int j = 0; j < count + 1; ++j) b[i - j] = c[count - j];
          count = 0;
        }
      }
      if (count > 0) {
        int c[count + 1];
        for (int j = 0; j < count + 1; ++j) c[j] = b[n - 1 - j];
        for (int j = 0; j < count + 1; ++j) b[n - 1 - j] = c[count - j];
        count = 0;
      }
      for (int i = 0; i < n; ++i) cout << b[i] + 1 << " ";
      cout << endl;
      for (int i = 0; i < n; ++i) b[i] = i;
      for (int i = 0; i < n - 1; ++i) {
        if (!a[i])
          ++count;
        else if (count > 0) {
          int c[count + 1];
          for (int j = 0; j < count + 1; ++j) c[j] = b[i - j];
          for (int j = 0; j < count + 1; ++j) b[i - j] = c[count - j];
          count = 0;
        }
      }
      if (count > 0) {
        int c[count + 1];
        for (int j = 0; j < count + 1; ++j) c[j] = b[n - 1 - j];
        for (int j = 0; j < count + 1; ++j) b[n - 1 - j] = c[count - j];
        count = 0;
      }
      for (int i = 0; i < n; ++i) cout << b[i] + 1 << " ";
      cout << endl;
    }
  }
}
