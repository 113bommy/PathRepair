#include <bits/stdc++.h>
using namespace std;
struct nodo {
  int cont;
  char letra;
  nodo(int C, char L) {
    cont = C;
    letra = L;
  }
};
bool isprime[1005];
int cont[128];
vector<int> primo;
vector<nodo> v;
int tam;
string res = "";
bool ok = 0;
string solve() {
  if (tam == 1) {
    ok = 1;
    return "YES";
  }
  for (int i = 0; i < tam; i++) res += "0";
  for (int i = 0; i < primo.size(); i++) {
    int ct = 0, ct1 = 0;
    char es = '0';
    for (int j = 1; j <= tam / primo[i]; j++) {
      if (res[j * primo[i] - 1] == '0')
        ct++;
      else {
        if (res[j * primo[i] - 1] != es) ct1++;
        es = res[j * primo[i] - 1];
      }
    }
    if (ct1 > 1) return "NO";
    if (ct1 == 1) {
      for (int j = 0; j < v.size(); j++) {
        if (v[j].letra == es) {
          if (v[j].cont < ct) return "NO";
          v[j].cont -= ct;
          break;
        }
      }
      for (int j = 1; j <= tam / primo[i]; j++) res[j * primo[i] - 1] = es;
    }
    if (ct1 == 0) {
      int ind = 0, maxi = 0;
      for (int j = 0; j < v.size(); j++) {
        if (v[j].cont > maxi) ind = j, maxi = v[j].cont;
      }
      if (v[ind].cont < ct) return "NO";
      v[ind].cont -= ct;
      for (int j = 1; j <= tam / primo[i]; j++)
        res[j * primo[i] - 1] = v[ind].letra;
    }
  }
  int pos = 0;
  for (int i = 0; i < v.size(); i++) {
    while (v[i].cont > 0) {
      if (res[pos] == '0') {
        res[pos] = v[i].letra;
        v[i].cont--;
      }
      pos++;
    }
  }
  ok = 1;
  return "YES";
}
int main() {
  string s;
  cin >> s;
  memset(isprime, 1, sizeof(isprime));
  tam = s.length();
  for (int i = 2; i * i <= tam; i++)
    if (isprime[i])
      for (int j = i * i; j <= tam; j += i) isprime[j] = 0;
  for (int i = 2; i <= tam; i++)
    if (isprime[i]) primo.push_back(i);
  for (int i = 0; i < tam; i++) cont[s[i]]++;
  for (char i = 'a'; i <= 'z'; i++)
    if (cont[i] > 0) v.push_back(nodo(cont[i], i));
  cout << solve() << endl;
  if (tam == 1) res = s;
  if (ok) cout << res << endl;
}
