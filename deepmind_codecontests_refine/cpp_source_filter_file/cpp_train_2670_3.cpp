#include <bits/stdc++.h>
using namespace std;
long long s[200001];
long long n, top;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[top++];
    while (top > 1 && s[top - 2] == s[top - 1]) {
      top--;
      s[top - 1]++;
    }
  }
  cout << top;
  for (int i = 0; i < top; i++) cout << s[i] << " ";
}
