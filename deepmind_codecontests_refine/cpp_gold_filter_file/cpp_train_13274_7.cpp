#include <bits/stdc++.h>
using namespace std;
int a2[4][4] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1}, a3[8][8],
    a4[16][16], a5[32][32], a6[64][64], a7[128][128], a8[256][256],
    a9[512][512];
int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "+" << endl;
    return 0;
  } else if (n == 1) {
    cout << "+*" << endl << "++" << endl;
    return 0;
  }
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      if (a2[x][y] == 1) {
        a3[x][2 * y] = 1;
        a3[x][2 * y + 1] = 1;
        a3[x + 4][2 * y] = 1;
        a3[x + 4][2 * y + 1] = 0;
      } else {
        a3[x][2 * y] = 0;
        a3[x][2 * y + 1] = 0;
        a3[x + 4][2 * y] = 0;
        a3[x + 4][2 * y + 1] = 1;
      }
    }
  }
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      if (a3[x][y] == 1) {
        a4[x][2 * y] = 1;
        a4[x][2 * y + 1] = 1;
        a4[x + 8][2 * y] = 1;
        a4[x + 8][2 * y + 1] = 0;
      } else {
        a4[x][2 * y] = 0;
        a4[x][2 * y + 1] = 0;
        a4[x + 8][2 * y] = 0;
        a4[x + 8][2 * y + 1] = 1;
      }
    }
  }
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      if (a4[x][y] == 1) {
        a5[x][2 * y] = 1;
        a5[x][2 * y + 1] = 1;
        a5[x + 16][2 * y] = 1;
        a5[x + 16][2 * y + 1] = 0;
      } else {
        a5[x][2 * y] = 0;
        a5[x][2 * y + 1] = 0;
        a5[x + 16][2 * y] = 0;
        a5[x + 16][2 * y + 1] = 1;
      }
    }
  }
  for (int x = 0; x < 32; x++) {
    for (int y = 0; y < 32; y++) {
      if (a5[x][y] == 1) {
        a6[x][2 * y] = 1;
        a6[x][2 * y + 1] = 1;
        a6[x + 32][2 * y] = 1;
        a6[x + 32][2 * y + 1] = 0;
      } else {
        a6[x][2 * y] = 0;
        a6[x][2 * y + 1] = 0;
        a6[x + 32][2 * y] = 0;
        a6[x + 32][2 * y + 1] = 1;
      }
    }
  }
  for (int x = 0; x < 64; x++) {
    for (int y = 0; y < 64; y++) {
      if (a6[x][y] == 1) {
        a7[x][2 * y] = 1;
        a7[x][2 * y + 1] = 1;
        a7[x + 64][2 * y] = 1;
        a7[x + 64][2 * y + 1] = 0;
      } else {
        a7[x][2 * y] = 0;
        a7[x][2 * y + 1] = 0;
        a7[x + 64][2 * y] = 0;
        a7[x + 64][2 * y + 1] = 1;
      }
    }
  }
  for (int x = 0; x < 128; x++) {
    for (int y = 0; y < 128; y++) {
      if (a7[x][y] == 1) {
        a8[x][2 * y] = 1;
        a8[x][2 * y + 1] = 1;
        a8[x + 128][2 * y] = 1;
        a8[x + 128][2 * y + 1] = 0;
      } else {
        a8[x][2 * y] = 0;
        a8[x][2 * y + 1] = 0;
        a8[x + 128][2 * y] = 0;
        a8[x + 128][2 * y + 1] = 1;
      }
    }
  }
  for (int x = 0; x < 256; x++) {
    for (int y = 0; y < 256; y++) {
      if (a8[x][y] == 1) {
        a9[x][2 * y] = 1;
        a9[x][2 * y + 1] = 1;
        a9[x + 256][2 * y] = 1;
        a9[x + 256][2 * y + 1] = 0;
      } else {
        a9[x][2 * y] = 0;
        a9[x][2 * y + 1] = 0;
        a9[x + 256][2 * y] = 0;
        a9[x + 256][2 * y + 1] = 1;
      }
    }
  }
  if (n == 2) {
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        if (a2[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else if (n == 3) {
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
        if (a3[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else if (n == 4) {
    for (int x = 0; x < 16; x++) {
      for (int y = 0; y < 16; y++) {
        if (a4[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else if (n == 5) {
    for (int x = 0; x < 32; x++) {
      for (int y = 0; y < 32; y++) {
        if (a5[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else if (n == 6) {
    for (int x = 0; x < 64; x++) {
      for (int y = 0; y < 64; y++) {
        if (a6[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else if (n == 7) {
    for (int x = 0; x < 128; x++) {
      for (int y = 0; y < 128; y++) {
        if (a7[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else if (n == 8) {
    for (int x = 0; x < 256; x++) {
      for (int y = 0; y < 256; y++) {
        if (a8[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  } else {
    for (int x = 0; x < 512; x++) {
      for (int y = 0; y < 512; y++) {
        if (a9[x][y] == 1)
          cout << '+';
        else
          cout << '*';
      }
      cout << endl;
    }
  }
  return 0;
}
