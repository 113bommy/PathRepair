#include <bits/stdc++.h>
using namespace std;
bool ISLETTER(char t) {
  if (t >= 'A' && t <= 'Z') return true;
  return false;
}
bool isletter(char t) {
  if (t >= 'a' && t <= 'z') return true;
  return false;
}
bool is_num(char t) {
  if (t >= '0' && t <= '9') return true;
  return false;
}
bool is_vowal(char t) {
  if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' || t == 'y')
    return true;
  if (t == 'A' || t == 'E' || t == 'I' || t == 'O' || t == 'U' || t == 'Y')
    return true;
  return false;
}
bool isLN(int aa) {
  while (aa) {
    if (aa % 10 != 4 && aa % 10 != 7) return false;
    aa /= 10;
  }
  return true;
}
int MOD(int aa) {
  if (aa < 0) aa *= -1;
  return aa;
}
int GCD(int a, int b) {
  if (a < b) swap(a, b);
  return (!b) ? a : GCD(b, a % b);
}
void DFS() {}
void BFS() {}
bool okok[1000005];
vector<int> divi[1000005];
int primes[1000005], cntp;
void Criba() {
  for (int i = 2; i < 1000005;) {
    if (!okok[i]) {
      primes[cntp++] = i;
      for (int j = 1; i < 1000005 / j; j++) {
        divi[i * j].push_back(i);
        okok[i * j] = true;
      }
    }
    if (i == 2)
      i++;
    else if (i == 3)
      i += 2;
    else if (i % 6 == 1)
      i += 4;
    else
      i += 2;
  }
}
void UpdateAbi(int idx, int s, int n, int* abi) {
  while (idx <= n) {
    abi[idx] += s;
    idx += (idx & -idx);
  }
}
void QueryAbi(int idx, int* abi) {
  int qresp(0);
  while (idx) {
    qresp += abi[idx];
    idx -= (idx & -idx);
  }
}
struct T {};
double a, b;
int main() {
  cin >> a;
  getchar();
  cin >> b;
  if (a == 12) a = 0;
  cout << a * 30 + b / 2 << " " << b * 6;
  return 0;
}
