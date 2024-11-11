#include <bits/stdc++.h>
using namespace std;
pair<unsigned long long, unsigned long long> vet[10000];
unsigned long long partenza, finoa, N, C, maxabitanti = 0;
unsigned long long giorni(unsigned long long x) {
  unsigned long long days = 0;
  for (int i = 0; i < N; i++) {
    days = days + 1 + ((vet[i].first * x) / vet[i].second);
  }
  return days;
}
int main(void) {
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> vet[i].first >> vet[i].second;
  }
  unsigned long long da = 1, a = INT_MAX;
  while (1) {
    if (da == a) {
      partenza = da;
      break;
    }
    unsigned long long centro = (da + a) / 2;
    unsigned long long days;
    days = giorni(centro);
    if (days < C)
      da = centro + 1;
    else
      a = centro;
  }
  if (giorni(partenza) != C) {
    cout << 0;
    return 0;
  }
  da = 1, a = INT_MAX;
  while (1) {
    if (da == a) {
      finoa = da;
      break;
    }
    unsigned long long centro = (da + a + 1) / 2;
    unsigned long long days;
    days = giorni(centro);
    if (days <= C)
      da = centro;
    else
      a = centro - 1;
  }
  if (finoa == INT_MAX) {
    cout << -1;
    return 0;
  }
  cout << finoa - partenza + 1;
  return 0;
}
