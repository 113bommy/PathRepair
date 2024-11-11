#include <bits/stdc++.h>
using namespace std;
map<string, int> ZJQ, JSQ, SC, Cnt;
map<string, bool> Used;
vector<string> Teams;
bool Cmp(string &A, string &B) {
  if (SC[A] > SC[B]) return 1;
  if (SC[A] < SC[B]) return 0;
  if (JSQ[A] > JSQ[B]) return 1;
  if (JSQ[A] < JSQ[B]) return 0;
  if (ZJQ[A] > ZJQ[B]) return 1;
  if (ZJQ[A] < ZJQ[B]) return 0;
  if (A > B) return 1;
  return 0;
}
int main() {
  for (int i = 0; i < 5; i++) {
    string A, B;
    cin >> A >> B;
    char _;
    int GA, GB;
    cin >> GA >> _ >> GB;
    if (!Used[A]) {
      Teams.push_back(A);
      Used[A] = true;
    }
    if (!Used[B]) {
      Teams.push_back(B);
      Used[B] = true;
    }
    ZJQ[A] += GA;
    ZJQ[B] += GB;
    JSQ[A] -= GB;
    JSQ[B] -= GA;
    JSQ[A] += GA;
    JSQ[B] += GB;
    Cnt[A]++;
    Cnt[B]++;
    if (GA == GB) {
      SC[A]++;
      SC[B]++;
    } else if (GA > GB)
      SC[A] += 3;
    else
      SC[B] += 3;
  }
  string Enemy;
  for (int i = 0; i < 4; i++)
    if (Cnt[Teams[i]] == 2 && Teams[i] != "BERLAND") Enemy = Teams[i];
  SC["BERLAND"] += 3;
  for (int i = 1; i < 100; i++)
    for (int j = 0; j < 100; j++) {
      JSQ["BERLAND"] += i;
      JSQ[Enemy] -= i;
      ZJQ["BERLAND"] += i + j;
      ZJQ[Enemy] += j;
      sort(Teams.begin(), Teams.end(), Cmp);
      if (Teams[0] == "BERLAND" || Teams[1] == "BERLAND") {
        cout << i + j << ":" << j << endl;
        return 0;
      }
      JSQ["BERLAND"] -= i;
      JSQ[Enemy] += i;
      ZJQ["BERLAND"] -= i + j;
      ZJQ[Enemy] -= j;
    }
  puts("IMPOSSIBLE");
  return 0;
}
