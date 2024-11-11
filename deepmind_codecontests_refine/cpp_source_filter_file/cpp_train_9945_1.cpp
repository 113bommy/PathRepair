#include <bits/stdc++.h>
using namespace std;
char bessi[4];
char elsi[4];
int getX(char* arr) {
  for (int i = 0; i < 4; i++) {
    if (arr[i] == 'X') return i;
  }
  return 0;
}
void init(char* arr, char p1, char p2, char p3, char p4) {
  arr[0] = p1;
  arr[1] = p2;
  arr[2] = p3;
  arr[3] = p4;
}
int print(char* arr) {
  cout << arr[0] << " " << arr[1] << endl;
  cout << arr[2] << " " << arr[3] << endl;
}
int k(char* arr) {
  char tmp = arr[0];
  arr[0] = arr[1];
  arr[1] = arr[3];
  arr[3] = arr[2];
  arr[2] = tmp;
}
void xr(char* arr) {
  int i = getX(arr);
  switch (i) {
    case 0: {
      arr[0] = arr[1];
      arr[1] = 'X';
    } break;
    case 1: {
      arr[1] = arr[3];
      arr[3] = 'X';
    } break;
    case 2: {
      arr[2] = arr[0];
      arr[0] = 'X';
    } break;
    case 3: {
      arr[3] = arr[2];
      arr[2] = 'X';
    } break;
  }
}
void xl(char* arr) {
  int i = getX(arr);
  switch (i) {
    case 0: {
      arr[0] = arr[2];
      arr[2] = 'X';
    } break;
    case 1: {
      arr[0] = arr[1];
      arr[1] = 'X';
    } break;
    case 2: {
      arr[2] = arr[3];
      arr[3] = 'X';
    } break;
    case 3: {
      arr[3] = arr[1];
      arr[1] = 'X';
    } break;
  }
}
bool cmp(char* arr, char* arr2) {
  for (int i = 0; i < 4; i++) {
    if (arr[i] != arr2[i]) return false;
  }
  return true;
}
void wr(char* arr) { cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]; }
int main() {
  wr(bessi);
  wr(elsi);
  for (int i = 0; i < 4; i++) {
    if (cmp(bessi, elsi)) {
      cout << "YES"
           << "\n";
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      if (cmp(bessi, elsi)) {
        cout << "YES"
             << "\n";
        return 0;
      }
      xr(bessi);
    }
    for (int i = 0; i < 4; i++) {
      if (cmp(bessi, elsi)) {
        cout << "YES"
             << "\n";
        return 0;
      }
      xl(bessi);
    }
    k(bessi);
  }
  cout << "NO"
       << "\n";
  return 0;
}
