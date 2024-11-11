#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p[800001];
ll t[400001];
ll n;
ll dor[2][200002], nagyobbd[2][200002];
void epit() {
  {
    stack<ll> verem;
    verem.push(0);
    for (ll i = 1; i <= n; i++) {
      while (t[verem.top()] <= t[i]) verem.pop();
      nagyobbd[0][i] = verem.top();
      verem.push(i);
    }
  }
  {
    stack<ll> verem;
    verem.push(n + 1);
    for (ll i = n; i >= 1; i--) {
      while (t[verem.top()] <= t[i]) verem.pop();
      nagyobbd[1][i] = verem.top();
      verem.push(i);
    }
  }
  {
    stack<ll> verem;
    verem.push(0);
    for (ll i = 1; i <= n; i++) {
      while ((t[verem.top()] | t[i]) == t[i]) verem.pop();
      dor[0][i] = verem.top();
      verem.push(i);
    }
  }
  {
    stack<ll> verem;
    verem.push(n + 1);
    for (ll i = n; i >= 1; i--) {
      while ((t[verem.top()] | t[i]) == t[i]) verem.pop();
      dor[1][i] = verem.top();
      verem.push(i);
    }
  }
}
ll ask_balra(ll honnan) { return dor[0][honnan]; }
ll ask_jobbra(ll honnan) { return dor[1][honnan]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> t[i];
  }
  t[0] = t[n + 1] = (1 << 30) - 1;
  epit();
  ll valasz = 0;
  for (int aktpoz = 1; aktpoz <= n; aktpoz++) {
    ll balrakisebb = nagyobbd[0][aktpoz] + 1;
    ll jobbrakisebb = nagyobbd[1][aktpoz] - 1;
    ll balra_elso = max(ask_balra(aktpoz), balrakisebb - 1),
       jobbra_elso = min(ask_jobbra(aktpoz), jobbrakisebb + 1);
    valasz += (aktpoz - balrakisebb + 1) * (jobbrakisebb - aktpoz + 1) -
              (aktpoz - balra_elso) * (jobbra_elso - aktpoz);
  }
  cout << valasz;
}
