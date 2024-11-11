#include <bits/stdc++.h>
using namespace std;
int nbridges;
long long potion;
long long length[200000], duration[200000];
void NO() {
  cout << "-1" << endl;
  exit(0);
}
vector<long long> uses;
long long nuses = 0;
void addUse(long long start, long long count) {
  nuses += count;
  if (uses.size() + count > 100000) return;
  for (int i = 0; i < count; i++) {
    uses.push_back(start);
    start += potion;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> nbridges >> potion;
  for (int i = 0; i < nbridges; i++) {
    cin >> length[i];
  }
  for (int i = 0; i < nbridges; i++) {
    cin >> duration[i];
  }
  long long leftover = 0;
  long long currtime = 0;
  for (int i = 0; i < nbridges; i++) {
    long long nonpotion = length[i] - leftover;
    if (duration[i] < length[i]) NO();
    long long potionNeeded = max(0ll, length[i] * 2 - duration[i] - leftover);
    long long potionBottles = (potionNeeded + potion - 1) / potion;
    if (potionBottles == 0) {
      long long thisdur = max(leftover + (length[i] - leftover) * 2, length[i]);
      leftover = max(0ll, leftover - length[i]);
      currtime += thisdur;
    } else {
      addUse(currtime + leftover, potionBottles - 1);
      long long nextLeftover = potionBottles * potion - potionNeeded;
      addUse(currtime + duration[i] - potion + nextLeftover, 1);
      leftover = nextLeftover;
      currtime += duration[i];
    }
  }
  cout << nuses << endl;
  if (nuses <= 100000) {
    for (int i = 0; i < nuses; i++) {
      cout << uses[i] << " ";
    }
    cout << endl;
  }
}
