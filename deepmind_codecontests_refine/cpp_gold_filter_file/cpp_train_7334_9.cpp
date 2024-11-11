#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
map<string, int> st;
string name[1010];
int cnt = 0;
pair<int, int> edges[1010];
vector<int> key1[1010];
int room1[1010];
int cid1[1010];
vector<int> comp1[1010];
vector<int> compkey1[1010];
vector<int> comproom1[1010];
bool iskey1[1010][1010];
bool act1[1010];
bool keyvis1[1010][1010];
bool roomvis1[1010][1010];
void un1(int a, int b) {
  for (int i = 0; i < (int)(comp1[b]).size(); i++) {
    comp1[a].push_back(comp1[b][i]);
  }
  for (int i = 0; i < (int)(compkey1[b]).size(); i++) {
    compkey1[a].push_back(compkey1[b][i]);
    iskey1[a][compkey1[b][i]] = true;
  }
  for (int i = 0; i < (int)(comproom1[b]).size(); i++) {
    comproom1[a].push_back(comproom1[b][i]);
    cid1[comproom1[b][i]] = a;
  }
  act1[b] = false;
}
vector<int> key2[1010];
int room2[1010];
int cid2[1010];
vector<int> comp2[1010];
vector<int> compkey2[1010];
vector<int> comproom2[1010];
bool iskey2[1010][1010];
bool act2[1010];
bool keyvis2[1010][1010];
bool roomvis2[1010][1010];
void un2(int a, int b) {
  for (int i = 0; i < (int)(comp2[b]).size(); i++) {
    comp2[a].push_back(comp2[b][i]);
  }
  for (int i = 0; i < (int)(compkey2[b]).size(); i++) {
    compkey2[a].push_back(compkey2[b][i]);
    iskey2[a][compkey2[b][i]] = true;
  }
  for (int i = 0; i < (int)(comproom2[b]).size(); i++) {
    comproom2[a].push_back(comproom2[b][i]);
    cid2[comproom2[b][i]] = a;
  }
  act2[b] = false;
}
int main() {
  memset(act1, true, sizeof(act1));
  memset(act2, true, sizeof(act2));
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[i] = make_pair(a, b);
  }
  for (int i = 1; i <= k; i++) {
    string s;
    cin >> s;
    int idx = i;
    name[idx] = s;
    st[s] = idx;
    int r;
    scanf("%d", &r);
    room1[idx] = r;
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      int a;
      scanf("%d", &a);
      key1[idx].push_back(a);
    }
  }
  for (int i = 1; i <= n; i++) {
    cid1[i] = i;
    comproom1[i].push_back(i);
  }
  for (int i = 1; i <= k; i++) {
    comp1[room1[i]].push_back(i);
    for (int j = 0; j < (int)(key1[i]).size(); j++) {
      compkey1[room1[i]].push_back(key1[i][j]);
      iskey1[room1[i]][key1[i][j]] = true;
    }
  }
  for (int step = 1;; step++) {
    bool ok = false;
    for (int i = 1; i <= m; i++) {
      int a = edges[i].first;
      int b = edges[i].second;
      if (cid1[a] != cid1[b]) {
        if (iskey1[cid1[a]][i] || iskey1[cid1[b]][i]) {
          un1(cid1[a], cid1[b]);
          ok = true;
        }
      }
    }
    if (!ok) break;
  }
  for (int i = 1; i <= n; i++) {
    if (act1[i]) {
      for (int j = 0; j < (int)(comp1[i]).size(); j++) {
        for (int x = 0; x < (int)(comproom1[i]).size(); x++) {
          roomvis1[comp1[i][j]][comproom1[i][x]] = true;
        }
        for (int x = 0; x < (int)(compkey1[i]).size(); x++) {
          keyvis1[comp1[i][j]][compkey1[i][x]] = true;
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    string s;
    cin >> s;
    int idx = st[s];
    int r;
    scanf("%d", &r);
    room2[idx] = r;
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      int a;
      scanf("%d", &a);
      key2[idx].push_back(a);
    }
  }
  for (int i = 1; i <= n; i++) {
    cid2[i] = i;
    comproom2[i].push_back(i);
  }
  for (int i = 1; i <= k; i++) {
    comp2[room2[i]].push_back(i);
    for (int j = 0; j < (int)(key2[i]).size(); j++) {
      compkey2[room2[i]].push_back(key2[i][j]);
      iskey2[room2[i]][key2[i][j]] = true;
    }
  }
  for (int step = 1;; step++) {
    bool ok = false;
    for (int i = 1; i <= m; i++) {
      int a = edges[i].first;
      int b = edges[i].second;
      if (cid2[a] != cid2[b]) {
        if (iskey2[cid2[a]][i] || iskey2[cid2[b]][i]) {
          un2(cid2[a], cid2[b]);
          ok = true;
        }
      }
    }
    if (!ok) break;
  }
  for (int i = 1; i <= n; i++) {
    if (act2[i]) {
      for (int j = 0; j < (int)(comp2[i]).size(); j++) {
        for (int x = 0; x < (int)(comproom2[i]).size(); x++) {
          roomvis2[comp2[i][j]][comproom2[i][x]] = true;
        }
        for (int x = 0; x < (int)(compkey2[i]).size(); x++) {
          keyvis2[comp2[i][j]][compkey2[i][x]] = true;
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (roomvis2[i][j] != roomvis1[i][j]) {
        printf("NO\n");
        return 0;
      }
    }
    for (int j = 1; j <= m; j++) {
      if (keyvis2[i][j] != keyvis1[i][j]) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}
