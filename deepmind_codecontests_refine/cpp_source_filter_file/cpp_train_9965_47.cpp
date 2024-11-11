#include <bits/stdc++.h>
using namespace std;
set<long long> st;
int n;
int v[] = {1, 5, 10, 50};
void gen(int digit, int sum) {
  if (digit == n) {
    st.insert(sum);
    return;
  }
  for (int i = 0; i < 4; i++) {
    gen(digit + 1, sum + v[i]);
  }
}
int main() {
  cin >> n;
  if (n <= 11) {
    gen(0, 0);
    cout << st.size();
  } else {
    int alpha = n;
    n = 11;
    gen(0, 0);
    cout << st.size() + (alpha - n) * 49;
  }
  return 0;
}
