#include <bits/stdc++.h>
using namespace std;
long long a1[10], an[10], N[10];
void buscaBinaria(long long q, int pos, long long& ann, long long& nn) {
  long long inicio = a1[pos];
  long long pa = pos + 1;
  long long hi = pow(10, pos + 1);
  long long lo = pow(10, pos);
  long long primeiro = pow(10, pos);
  while (hi - lo > 1) {
    long long mid = (hi + lo) >> 1;
    long long fim = inicio + (mid - primeiro) * pa;
    long long sn = ((inicio + fim) * (mid - primeiro + 1)) / 2;
    if (sn < q)
      lo = mid;
    else
      hi = mid;
  }
  ann = inicio + (lo - primeiro) * pa;
  nn = lo - primeiro + 1;
}
int main() {
  a1[0] = 1;
  an[0] = 9;
  N[0] = 9;
  a1[1] = 11;
  an[1] = 189;
  N[1] = 90;
  a1[2] = 192;
  an[2] = 2889;
  N[2] = 900;
  a1[3] = 2893;
  an[3] = 38889;
  N[3] = 9000;
  a1[4] = 38894;
  an[4] = 488889;
  N[4] = 90000;
  a1[5] = 488895;
  an[5] = 5888889;
  N[5] = 900000;
  a1[6] = 5888896;
  an[6] = 68888889;
  N[6] = 9000000;
  a1[7] = 68888897;
  an[7] = 788888889;
  N[7] = 90000000;
  a1[8] = 788888898;
  an[8] = 8888888889;
  N[8] = 900000000;
  long long n;
  cin >> n;
  while (n--) {
    long long q;
    cin >> q;
    if (q == 1) {
      cout << "1\n";
      continue;
    }
    int pos = 0;
    while (true) {
      long long sn = ((a1[pos] + an[pos]) * N[pos]) / 2;
      if (sn < q)
        q -= sn;
      else
        break;
      pos++;
    }
    long long ann, nn;
    buscaBinaria(q, pos, ann, nn);
    long long sn = ((a1[pos] + ann) * nn) / 2;
    if (sn < q) q -= sn;
    long long aux = 8;
    while (aux > 0 && an[aux] >= q) aux--;
    long long inicio = 1, aux2;
    if (an[aux] < q) {
      inicio = pow(10, aux + 1);
      aux2 = aux + 2;
      q -= an[aux];
    } else {
      inicio = pow(10, aux);
      aux2 = aux + 1;
    }
    if (q > 100) {
      aux = q / aux2;
      aux--;
      if (q > aux2 * aux) {
        q -= (aux2 * aux);
        inicio = inicio + aux;
      }
    }
    for (long long i = inicio;; i++) {
      string s;
      stringstream ss;
      ss << i;
      ss >> s;
      if (s.size() >= q) {
        cout << s[q - 1] << endl;
        break;
      } else
        q -= s.size();
    }
  }
}
