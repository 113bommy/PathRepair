#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int odd[2], even[2], odd_ans, even_ans, n;
char second[N];
int main() {
  scanf("%s", second);
  n = strlen(second);
  for (int i = 0; i < n; i++) {
    int a = second[i] - 'a';
    if (i % 2 == 0) {
      even[a]++;
      even_ans += odd[a];
      odd_ans += even[a];
    } else {
      odd[a]++;
      odd_ans += odd[a];
      even_ans += even[a];
    }
  }
  cout << even_ans << " " << odd_ans;
  return 0;
}
