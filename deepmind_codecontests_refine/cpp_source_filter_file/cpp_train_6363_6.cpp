#include <bits/stdc++.h>
using namespace std;
struct cord {
  int x, y;
};
bool cmp(cord a, cord b) {
  return ((a.x < b.x) || ((a.x == b.x) && (a.y < b.y)));
}
int main() {
  cord a, b, c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  cord mas[3];
  int i, j, cx, cy;
  mas[0] = a;
  mas[1] = b;
  mas[2] = c;
  sort(mas, mas + 3, cmp);
  cord curr;
  vector<cord> res;
  if ((mas[0].y <= mas[1].y) && (mas[1].y <= mas[2].y)) {
    cx = mas[0].x;
    cy = mas[0].y;
    while (cy < mas[1].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy++;
    }
    while (cx < mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    while (cy < mas[2].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy++;
    }
    while (cx <= mas[2].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x << " " << res[i].y << endl;
    return 0;
  }
  if ((mas[0].y >= mas[1].y) && (mas[1].y >= mas[2].y)) {
    cx = mas[0].x;
    cy = mas[0].y;
    while (cy > mas[1].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy--;
    }
    while (cx < mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    while (cy > mas[2].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy--;
    }
    while (cx <= mas[2].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x << " " << res[i].y << endl;
    return 0;
  }
  if ((mas[0].y <= mas[2].y) && (mas[2].y <= mas[1].y)) {
    cx = mas[0].x;
    cy = mas[0].y;
    while (cx < mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    while (cy <= mas[1].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy++;
    }
    cx = mas[2].x;
    cy = mas[2].y;
    while (cx > mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx--;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x << " " << res[i].y << endl;
    return 0;
  }
  if ((mas[0].y >= mas[2].y) && (mas[0].y <= mas[1].y)) {
    cx = mas[2].x;
    cy = mas[2].y;
    while (cx > mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx--;
    }
    while (cy <= mas[1].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy++;
    }
    cx = mas[0].x;
    cy = mas[0].y;
    while (cx > mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x << " " << res[i].y << endl;
    return 0;
  }
  if ((mas[0].y >= mas[2].y) && (mas[1].y <= mas[2].y)) {
    cx = mas[0].x;
    cy = mas[0].y;
    while (cx < mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    while (cy >= mas[1].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy--;
    }
    cx = mas[2].x;
    cy = mas[2].y;
    while (cx > mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx--;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x << " " << res[i].y << endl;
    return 0;
  }
  if ((mas[0].y <= mas[2].y) && (mas[1].y <= mas[0].y)) {
    cx = mas[2].x;
    cy = mas[2].y;
    while (cx > mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx--;
    }
    while (cy >= mas[1].y) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cy--;
    }
    cx = mas[0].x;
    cy = mas[0].y;
    while (cx < mas[1].x) {
      curr.x = cx;
      curr.y = cy;
      res.push_back(curr);
      cx++;
    }
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++)
      cout << res[i].x << " " << res[i].y << endl;
    return 0;
  }
}
