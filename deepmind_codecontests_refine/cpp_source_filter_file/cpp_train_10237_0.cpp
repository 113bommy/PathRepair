#include <bits/stdc++.h>
using namespace std;
struct block {
  int size;
  int id;
};
bool operator<(block b1, block b2) { return b1.size > b2.size; }
struct color {
  vector<block> blocks;
  long long sum;
} colors[100005];
bool operator<(color c1, color c2) {
  if (((int)(c1.blocks).size()) == ((int)(c2.blocks).size()))
    return c1.sum < c2.sum;
  return ((int)(c1.blocks).size()) < ((int)(c2.blocks).size());
}
map<int, int> mymap;
int mapcnt = 0;
long long cumsum[100005];
int todo[100005];
int todocnt = 0;
int ans1, ans2;
long long curmax = -1;
int main() {
  int n;
  cin >> n;
  int i, j;
  for ((i) = 0; (i) < (int)(n); (i)++) {
    int c, s;
    cin >> c >> s;
    if (mymap[c] == 0) {
      mymap[c] = mapcnt + 1;
      mapcnt++;
    }
    block myblock;
    myblock.size = s;
    myblock.id = i + 1;
    colors[mymap[c] - 1].blocks.push_back(myblock);
  }
  for ((i) = 0; (i) < (int)(mapcnt); (i)++) {
    sort((colors[i].blocks).begin(), (colors[i].blocks).end());
    reverse((colors[i].blocks).begin(), (colors[i].blocks).end());
    colors[i].sum = 0;
    for ((j) = 0; (j) < (int)(((int)(colors[i].blocks).size())); (j)++)
      colors[i].sum += colors[i].blocks[j].size;
  }
  sort(colors, colors + mapcnt);
  for ((i) = 0; (i) < (int)(mapcnt); (i)++) {
    cumsum[0] = 0;
    for (j = 1; j <= ((int)(colors[i].blocks).size()); j++)
      cumsum[j] = cumsum[j - 1] + colors[i].blocks[j - 1].size;
    for ((j) = 0; (j) < (int)(todocnt); (j)++) {
      long long z = colors[todo[j]].sum;
      long long zz = cumsum[min(((int)(colors[todo[j]].blocks).size()) + 1,
                                ((int)(colors[i].blocks).size()))];
      if (z + zz > curmax) {
        ans1 = todo[j];
        ans2 = i;
        curmax = z + zz;
      }
    }
    if (todocnt == 0 || (((int)(colors[todocnt - 1].blocks).size()) !=
                         ((int)(colors[i].blocks).size()))) {
      todo[todocnt++] = i;
    } else {
      todo[todocnt - 1] = i;
    }
  }
  if (ans1 < ans2) swap(ans1, ans2);
  int sz1 = min(((int)(colors[ans1].blocks).size()),
                ((int)(colors[ans2].blocks).size()) + 1);
  int sz2 = ((int)(colors[ans2].blocks).size());
  long long numans = 0;
  for ((i) = 0; (i) < (int)(sz1); (i)++) numans += colors[ans1].blocks[i].size;
  for ((i) = 0; (i) < (int)(sz2); (i)++) numans += colors[ans2].blocks[i].size;
  cout << numans << endl << sz1 + sz2 << endl;
  for ((i) = 0; (i) < (int)(sz2); (i)++) {
    cout << colors[ans1].blocks[i].id << " " << colors[ans2].blocks[i].id
         << " ";
  }
  if (sz1 > sz2) cout << colors[ans1].blocks[sz1 - 1].id;
  cin.get();
  cin.get();
  return 0;
}
