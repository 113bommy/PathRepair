#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n;
  int total;
  bool has = true;
  int result = 0;
  cin >> n;
  cin >> total;
  int a[101];
  int c[101];
  float answer[101];
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  for (int j = 2; j < n + 1; j++) {
    c[j] = a[j] - a[1];
    result += c[j];
  }
  answer[1] = (float)(total + result) / n;
  if (answer[1] > 0) {
    for (int i = 2; i < n + 1; i++) {
      answer[i] = answer[1] - c[i];
      if (answer[i] < 0) {
        has = false;
        break;
      }
    }
  }
  if (has)
    for (int i = 1; i < n + 1; i++) {
      printf("%.5f", answer[i]);
      cout << endl;
    }
  else
    cout << "-1";
}
