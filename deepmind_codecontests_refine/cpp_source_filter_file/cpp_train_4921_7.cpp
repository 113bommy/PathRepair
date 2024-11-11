#include <bits/stdc++.h>
using namespace std;
const long long NN = 1e6 + 5;
long long t, n;
char a[NN], kir[NN], kan[NN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  char las = '?';
  for (long long i = 0; i < n; i++)
    if (a[i] != '?')
      las = a[i];
    else
      kir[i] = las;
  las = '?';
  for (long long i = n - 1; i >= 0; i--)
    if (a[i] != '?')
      las = a[i];
    else
      kan[i] = las;
  for (long long i = 0; i < n; i++) {
    if (kir[i] == '?' && kan[i] == '?')
      a[i] = '1';
    else if (kir[i] == '?')
      a[i] = kan[i];
    else if (kan[i] == '?')
      a[i] = kir[i];
    else if (kir[i] == '0' && kan[i] == '0')
      a[i] = kir[i];
    else if (kir[i] == '1' && kan[i] == '1')
      a[i] = kir[i];
  }
  vector<long long> tmp;
  long long hz = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '0') {
      hz++;
      if (i == (n - 1) || a[i + 1] == '1') {
        tmp.push_back(hz);
        tmp.push_back(0);
        hz = 0;
      } else if (a[i + 1] == '?') {
        tmp.push_back(hz);
        hz = 0;
      }
    } else if (a[i] == '1') {
      hz++;
      if (i == (n - 1) || a[i + 1] == '0') {
        tmp.push_back(hz);
        tmp.push_back(0);
        hz = 0;
      } else if (a[i + 1] == '?') {
        tmp.push_back(hz);
        hz = 0;
      }
    } else {
      hz++;
      if (i == (n - 1) || a[i + 1] != '?') {
        tmp.push_back(hz);
        hz = 0;
      }
    }
  }
  vector<pair<long long, long long> > isi;
  for (long long i = 0; i < tmp.size(); i += 2)
    isi.push_back(make_pair(tmp[i], tmp[i + 1]));
  for (long long i = 1; i <= n; i++) {
    vector<pair<long long, long long> > tmp2;
    long long sisa = 0, jaw = 0;
    for (long long j = 0; j < isi.size(); j++) {
      long long nw = isi[j].first + isi[j].second + sisa;
      jaw += nw / i;
      sisa = min(isi[j].second, nw % i);
    }
    long long sz = isi.size();
    for (long long j = 0; j < isi.size(); j++) {
      long long maxi = isi[j].first + isi[j].second;
      if (j > 0) maxi += isi[j].second;
      if (maxi <= i) {
        if ((j + 1) < sz) isi[j + 1].first += isi[j].second;
        isi[j] = make_pair(0, 0);
      }
    }
    for (long long j = 0; j < isi.size(); j++) {
      if (isi[j].first == 0 && isi[j].second == 0) {
        if (j == 0 || (isi[j - 1].first != 0 || isi[j - 1].second != 0))
          tmp2.push_back(isi[j]);
      } else
        tmp2.push_back(isi[j]);
    }
    isi = tmp2;
    cout << jaw << " ";
  }
  cout << "\n";
}
