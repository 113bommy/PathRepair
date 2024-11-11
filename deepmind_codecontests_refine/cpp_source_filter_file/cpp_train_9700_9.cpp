#include <bits/stdc++.h>
using namespace std;
bool chon[101];
vector<int> card[101];
vector<int> b;
int a[101];
double val[101];
double lon, nho;
int n, k, q;
bool diff(vector<int> a, vector<int> b) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i]) return true;
  return false;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n / k; j++) {
      int tam;
      cin >> tam;
      chon[tam] = true;
      card[i].push_back(tam);
    }
    sort(card[i].begin(), card[i].end());
  }
  if (q == 0) {
    for (int i = 0; i < n; i++) b.push_back(a[i]);
    sort(b.begin(), b.end());
    for (int i = 0; i < n / k; i++) {
      nho += b[i];
      lon += b[int(b.size()) - 1 - i];
    }
    nho /= (n / k);
    lon /= (n / k);
    printf("%0.9lf %0.9lf", nho, lon);
    return 0;
  }
  for (int i = 0; i < card[0].size(); i++) val[0] += a[card[0][i]];
  val[0] /= card[0].size();
  lon = val[0];
  nho = val[0];
  for (int i = 1; i < q; i++)
    if (diff(card[i], card[i - 1])) {
      for (int j = 0; j < card[i].size(); j++) val[i] += a[card[i][j]];
      val[i] /= card[i].size();
      nho = min(nho, val[i]);
      lon = max(lon, val[i]);
    }
  for (int i = 1; i <= n; i++)
    if (chon[i] == false) b.push_back(a[i]);
  sort(b.begin(), b.end());
  if (b.size() > n - k * (n / k)) {
    double canNho = 0;
    double canLon = 0;
    for (int i = 0; i < n / k; i++) {
      canNho += b[i];
      canLon += b[int(b.size()) - 1 - i];
    }
    canNho /= (n / k);
    canLon /= (n / k);
    nho = min(nho, canNho);
    lon = max(lon, canLon);
  }
  printf("%0.9lf %0.9lf", nho, lon);
}
