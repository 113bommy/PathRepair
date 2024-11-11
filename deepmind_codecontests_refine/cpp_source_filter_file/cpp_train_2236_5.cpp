#include <bits/stdc++.h>
using namespace std;
long long int N, K;
set<long long int> st;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  long long int i, s, f, aux;
  for (i = 1; i <= min(K, N); i++) {
    cin >> s >> f;
    st.insert(s + f);
    cout << s + f << "\n";
  }
  for (i = K + 1; i <= N; i++) {
    cin >> s >> f;
    aux = *st.begin();
    st.erase(st.begin());
    if (aux >= s) {
      cout << aux + f << "\n";
      st.insert(aux + f);
    } else {
      cout << s + f << "\n";
      st.insert(s + f);
    }
  }
  return 0;
}
