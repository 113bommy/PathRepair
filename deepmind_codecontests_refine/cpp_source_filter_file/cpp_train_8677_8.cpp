#include <bits/stdc++.h>
using namespace std;
vector<long long int> crivo;
vector<pair<long long int, long long int> > leitor;
bool bob[212345];
void fazCrivo() {
  long long int index = 0;
  for (long long int i = 2; i < 1000000; i++) {
    bool primo = true;
    if (i == 2)
      crivo.push_back(2);
    else {
      for (long long int j = 0;
           j < crivo.size() && crivo[j] < (long long int)(sqrt(i) + 1); j++) {
        if (i % crivo[j] == 0) {
          primo = false;
          break;
        }
      }
    }
    if (primo) {
      crivo.push_back(i);
      while (index < leitor.size() && leitor[index].first < i * i) {
        bob[leitor[index].second] = false;
        index++;
      }
      if (index < leitor.size() && leitor[index].first == i * i) {
        bob[leitor[index].second] = true;
        index++;
      }
      if (index >= leitor.size()) break;
    }
  }
}
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    leitor.push_back(make_pair(x, i));
  }
  sort(leitor.begin(), leitor.end());
  fazCrivo();
  for (long long int i = 0; i < n; i++) {
    string aux = (bob[i]) ? "YES\n" : "NO\n";
    cout << aux;
  }
  return 0;
}
