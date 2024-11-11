#include <bits/stdc++.h>
using namespace std;
long long int modulo = 12345;
vector<vector<long long int> > operator*(vector<vector<long long int> > m1,
                                         vector<vector<long long int> > m2) {
  int n = int(m1.size());
  vector<vector<long long int> > r(n, vector<long long int>(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        r[i][j] = (r[i][j] + m1[i][k] * m2[k][j]) % modulo;
  return r;
}
vector<vector<long long int> > expo(vector<vector<long long int> > m,
                                    long long int e) {
  if (e == 0) {
    int n = int(m.size());
    vector<vector<long long int> > r(n, vector<long long int>(n, 0));
    for (int i = 0; i < n; i++) r[i][i] = 1;
    return r;
  }
  if (e % 2 == 0) return expo(m * m, e / 2);
  return m * expo(m * m, e / 2);
}
vector<long long int> operator*(vector<vector<long long int> > m,
                                vector<long long int> v) {
  int n = int(v.size());
  vector<long long int> r(n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) r[i] = (r[i] + m[i][j] * v[j]) % modulo;
  return r;
}
vector<int> maximo;
int codigo(vector<int> v) {
  int c = v[0];
  for (int i = 1; i < int(v.size()); i++) {
    c = c * maximo[i] + v[i];
  }
  return c;
}
vector<int> estado(int c) {
  vector<int> v;
  for (int i = int(maximo.size()) - 1; i >= 0; i--) {
    v.push_back(c % maximo[i]);
    c /= maximo[i];
  }
  reverse(v.begin(), v.end());
  return v;
}
bool divisible(int x, set<int> s) {
  for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    if (x % (*it) == 0) return true;
  return false;
}
int producto(set<int> s) {
  int p = 1;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) p *= (*it);
  return p;
}
int main() {
  long long int n, cuantos;
  cin >> n >> cuantos;
  map<char, set<int> > m;
  for (int i = 0; i < cuantos; i++) {
    char c;
    int val;
    cin >> c >> val;
    m[c].insert(val);
  }
  vector<set<int> > v;
  for (map<char, set<int> >::iterator it = m.begin(); it != m.end(); it++)
    v.push_back(it->second);
  maximo = vector<int>(int(v.size()));
  int numestados = 1;
  for (int i = 0; i < int(v.size()); i++) {
    maximo[i] = producto(v[i]);
    numestados *= maximo[i];
  }
  vector<int> aceptador(numestados, 1);
  vector<vector<long long int> > matriz(numestados,
                                        vector<long long int>(numestados, 0));
  for (int i = 0; i < numestados; i++) {
    vector<int> e = estado(i);
    vector<int> nexte = e;
    for (int j = 0; j < int(maximo.size()); j++) {
      if (not divisible(e[j], v[j])) aceptador[i] = 0;
      nexte[j] = (nexte[j] + 1) % maximo[j];
      int c = codigo(nexte);
      matriz[c][i] = 1;
      nexte[j] = e[j];
    }
  }
  vector<long long int> ini(numestados, 0);
  ini[0] = 1;
  vector<long long int> fin = expo(matriz, n) * ini;
  long long int suma = 0;
  for (int i = 0; i < numestados; i++) {
    if (aceptador[i]) suma = (suma + fin[i]) % modulo;
  }
  cout << suma << endl;
}
