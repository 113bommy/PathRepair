#include <bits/stdc++.h>
using namespace std;
struct widget {
  int N;
  string type;
  string name;
  long long int x, y;
  long long int border, space;
  int packed;
  int pack[100];
};
struct widget W[110];
int NS[110];
int NW = 0;
bool compi(struct widget w1, struct widget w2) {
  if (w1.name.compare(w2.name) < 0) return true;
  return false;
}
void area_comp(int obj) {
  if (W[obj].x != -1) return;
  if (W[obj].type.compare("VBox") == 0) {
    W[obj].x = 0;
    W[obj].y = 0;
    for (int i = 0; i < W[obj].packed; i++) {
      area_comp(NS[W[obj].pack[i]]);
      W[obj].y += W[NS[W[obj].pack[i]]].y + W[obj].space;
      if (W[NS[W[obj].pack[i]]].x > W[obj].x)
        W[obj].x = W[NS[W[obj].pack[i]]].x;
    }
    if (W[obj].packed > 0) {
      W[obj].y -= W[obj].space;
      W[obj].y += 2 * W[obj].border;
      W[obj].x += 2 * W[obj].border;
    }
  } else {
    W[obj].x = 0;
    W[obj].y = 0;
    for (int i = 0; i < W[obj].packed; i++) {
      area_comp(NS[W[obj].pack[i]]);
      W[obj].x += W[NS[W[obj].pack[i]]].x + W[obj].space;
      if (W[NS[W[obj].pack[i]]].y > W[obj].y)
        W[obj].y = W[NS[W[obj].pack[i]]].y;
    }
    if (W[obj].packed > 0) {
      W[obj].x -= W[obj].space;
      W[obj].x += 2 * W[obj].border;
      W[obj].y += 2 * W[obj].border;
    }
  }
}
int main() {
  int nin;
  char inp[10000];
  cin >> nin;
  cin.getline(inp, 10);
  struct widget ws;
  for (int i = 0; i < nin; i++) {
    cin.getline(inp, 10000);
    string s(inp);
    if (s.substr(0, 7).compare("Widget ") == 0) {
      ws.type = "Widget";
      int c = 6;
      while (s[c] != '(') c++;
      ws.name = s.substr(7, c - 7);
      int v = c;
      while (s[v] != ',') v++;
      ws.x = atoi(s.substr(c + 1, v - c - 1).c_str());
      c = v;
      while (s[c] != ')') c++;
      ws.y = atoi(s.substr(v + 1, c - v - 1).c_str());
      ws.packed = 0;
      ws.N = NW;
      NW++;
      W[NW - 1] = ws;
      continue;
    }
    if (s.substr(0, 5).compare("VBox ") == 0) {
      ws.type = "VBox";
      ws.name = s.substr(5, s.size() - 5);
      ws.x = -1;
      ws.y = -1;
      ws.border = 0;
      ws.space = 0;
      ws.packed = 0;
      ws.N = NW;
      NW++;
      W[NW - 1] = ws;
      continue;
    }
    if (s.substr(0, 5).compare("HBox ") == 0) {
      ws.type = "HBox";
      ws.name = s.substr(5, s.size() - 5);
      ws.x = -1;
      ws.y = -1;
      ws.border = 0;
      ws.space = 0;
      ws.packed = 0;
      ws.N = NW;
      NW++;
      W[NW - 1] = ws;
      continue;
    }
    int c = 0;
    while (s[c] != '.') c++;
    string name = s.substr(0, c);
    int obj = 0;
    for (obj = 0; obj < NW; obj++) {
      if (W[obj].name.compare(name) == 0) break;
    }
    if (s.substr(c + 1, 4).compare("pack") == 0) {
      int v = c + 1;
      while (s[v] != ')') v++;
      W[obj].packed++;
      name = s.substr(c + 6, v - c - 6);
      int obji = 0;
      for (obji = 0; obji < NW; obji++) {
        if (W[obji].name.compare(name) == 0) break;
      }
      W[obj].pack[W[obj].packed - 1] = obji;
      continue;
    }
    if (s.substr(c + 1, 10).compare("set_border") == 0) {
      int v = c + 1;
      while (s[v] != ')') v++;
      W[obj].border = atoi(s.substr(c + 12, v - c - 12).c_str());
      continue;
    }
    int v = c + 1;
    while (s[v] != ')') v++;
    W[obj].space = atoi(s.substr(c + 13, v - c - 13).c_str());
  }
  sort(W, W + NW, compi);
  for (int i = 0; i < NW; i++) NS[W[i].N] = i;
  for (int i = 0; i < NW; i++) {
    if (W[i].x == -1) area_comp(i);
    cout << W[i].name << ' ' << W[i].x << ' ' << W[i].y << endl;
  }
  return 0;
}
