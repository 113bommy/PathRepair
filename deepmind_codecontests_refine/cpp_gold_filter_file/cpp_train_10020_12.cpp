#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
  int t = 1, u = 1;
  scanf("%d", &t);
  while (t--) {
    cin >> n >> x;
    int ad2[1001];
    for (int i = 1; i <= 1000; i++) ad2[i] = 0;
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      ad2[a]++, ad2[b]++;
    }
    if (ad2[x] <= 1)
      cout << "Ayush\n";
    else {
      if (n % 2)
        cout << "Ashish\n";
      else
        cout << "Ayush\n";
    }
  }
}
