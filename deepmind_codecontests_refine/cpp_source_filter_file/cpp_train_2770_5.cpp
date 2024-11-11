#include <bits/stdc++.h>
using namespace std;
int n = 0, k, m, a;
pair<int, int> g[104];
pair<int, int> g_copy[104];
int aux;
void Copi() {
  for (int i = 0; i < n; i++) g_copy[i] = g[i];
}
bool pair_comp(const pair<int, int> &p1, const pair<int, int> &p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first > p2.first;
}
void Show(pair<int, int> *arr) {
  for (int i = 0; i < n; i++, *arr++)
    cout << arr->first << " " << arr->second << endl;
}
bool Step1(int index) {
  Copi();
  g_copy[index].first += m - a;
  g_copy[index].second = (m - a == 0) ? g_copy[index].second : m - 1;
  int findi = g_copy[index].second;
  if (findi == 0) return 0;
  sort(g_copy, g_copy + n, pair_comp);
  for (int i = 0; i < k; i++)
    if (g_copy[i].second == findi) return 1;
  return 0;
}
bool Step2(int index) {
  Copi();
  int rem = m - a;
  int cur = g_copy[index].first;
  int findi = g_copy[index].second;
  if (cur == 0 && n > 1) return 1;
  sort(g_copy, g_copy + n, pair_comp);
  for (int i = 0; i < n; i++) {
    if (g_copy[i].second != findi)
      if (g_copy[i].first < cur ||
          (g_copy[i].first == cur && g_copy[i].second > findi)) {
        int diff =
            (rem > cur - g_copy[i].first) ? cur - g_copy[i].first + 1 : rem;
        g_copy[i].first += diff;
        rem -= diff;
        if (diff > 0) g_copy[i].second = m - 1;
      }
    if (rem == 0) break;
  }
  sort(g_copy, g_copy + n, pair_comp);
  for (int i = 0; i < k; i++)
    if (g_copy[i].second == findi) return 0;
  return 1;
}
int main() {
  for (int i = 0; i < 104; i++) {
    g[i] = make_pair(0, 0);
  }
  cin >> n >> k >> m >> a;
  for (int i = 0; i < a; i++) {
    cin >> aux;
    aux--;
    g[aux].first++;
    g[aux].second = i + 1;
  }
  for (int i = 0; i < n; i++) {
    bool s1 = Step1(i);
    bool s2 = Step2(i);
    if (s1 && !s2)
      cout << "1 ";
    else if (s1)
      cout << "2 ";
    else
      cout << "3 ";
  }
  return 0;
}
