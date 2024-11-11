#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long long MOD = 4294967296;
const long long NO_OPERTATION = -1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t != 0) {
    t--;
    int n;
    int k;
    cin >> n >> k;
    vector<vector<long long> > v(k);
    for (int i = 0; i < k; i++) {
      int c;
      cin >> c;
      for (int j = 0; j < c; j++) {
        int a;
        cin >> a;
        v[i].push_back(a);
      }
    }
    int maior;
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
    cin >> maior;
    int ini = 1;
    int fim = n;
    while (ini <= fim) {
      int meio = (ini + fim) / 2;
      cout << "? " << meio - ini + 1 << " ";
      for (int i = ini; i <= meio; i++) {
        cout << i << " ";
      }
      cout << endl;
      int qual;
      cin >> qual;
      if (qual == maior) {
        if (fim == ini) {
          break;
        }
        fim = meio;
      } else {
        ini = meio + 1;
      }
    }
    vector<int> ans(k, maior);
    for (int i = 0; i < k; i++) {
      bool encontrou = false;
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] == fim) {
          encontrou = true;
        }
      }
      if (encontrou == true) {
        cout << "? " << n - v[i].size() << " ";
        set<int> sett;
        for (int j = 0; j < v[i].size(); j++) {
          sett.insert(v[i][j]);
        }
        for (int j = 1; j <= n; j++) {
          if (sett.count(j) == 0) {
            cout << j << " ";
          }
        }
        cout << endl;
        int aux;
        cin >> aux;
        ans[i] = aux;
        break;
      }
    }
    cout << "! ";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
    string second;
    cin >> second;
  }
  return 0;
}
