#include <bits/stdc++.h>
using namespace std;
vector<int> Vfront;
vector<int> Vend;
int hit = 0;
bool tr[1000000] = {0};
int front[1000000] = {0};
int back[1000000] = {0};
int latest;
void createQueueF(int index) {
  tr[index] = true;
  if (front[index] != 0) {
    Vfront.push_back(front[index]);
    createQueueF(front[index]);
  }
}
void createQueueB(int index) {
  if (back[index] != 0) {
    Vend.push_back(back[index]);
    createQueueB(back[index]);
  }
}
void createQueueBB(int index) {
  if (front[index] != 0) {
    Vend.push_back(front[index]);
    createQueueBB(front[index]);
  }
}
void traverse(int index) {
  if (back[index] != 0) {
    traverse(back[index]);
  } else {
    latest = index;
    Vend.push_back(index);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int dpn, blkg;
    cin >> dpn >> blkg;
    front[dpn] = blkg;
    back[blkg] = dpn;
  }
  int qwer = 0;
  if (n % 2 == 1)
    hit = 2;
  else
    hit = 0;
  createQueueF(0);
  if (hit != 2) {
    createQueueB(0);
  } else {
    int aa = -1;
    for (int j = 0; j < 100000; j++) {
      if (tr[j] == false && back[j] != 0) {
        aa = back[j];
      }
      if (tr[j] == true) {
        qwer += 1;
      }
    }
    if (qwer == n) hit = 3;
    if (aa != -1) traverse(aa);
    createQueueBB(latest);
  }
  Vend;
  Vfront;
  int it_a = 0;
  int it_b = 0;
  if (hit == 0) {
    it_b = Vend.size() - 1;
  } else
    it_b = 0;
  int c = 0;
  bool f = false;
  while (c <= Vfront.size() + Vend.size() - 1) {
    if (!f) {
      cout << Vend.at(it_b) << " ";
      if (hit != 3) {
        if (hit == 0) {
          it_b--;
        } else
          it_b++;
      }
      f = true;
    } else {
      cout << Vfront.at(it_a) << " ";
      it_a++;
      f = false;
    }
    c += 1;
  }
  getchar();
  getchar();
  return 0;
}
