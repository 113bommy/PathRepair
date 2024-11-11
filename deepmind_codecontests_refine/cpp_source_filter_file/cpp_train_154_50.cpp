#include <bits/stdc++.h>
using namespace std;
int idx, use_pow = 0;
double m;
double results[12];
double x, y, z;
double chain(double a, double b, double c) {
  if (use_pow) return pow(a, (double)pow(b, c));
  if (a <= (double)1.0) return -1000000000;
  return log10(log10(a)) + c * log10(b);
}
double parenthesis(double a, double b, double c) {
  if (use_pow) return pow((double)pow(a, b), c);
  if (a <= (double)1.0) return -1000000000;
  return log10(log10(a)) + log10(b) + log10(c);
}
void output(int idx) {
  switch (idx) {
    case 1: {
      cout << "x^y^z" << endl;
      break;
    }
    case 2: {
      cout << "x^z^y" << endl;
      break;
    }
    case 3: {
      cout << "(x^y)^z" << endl;
      break;
    }
    case 4: {
      cout << "(x^z)^y" << endl;
      break;
    }
    case 5: {
      cout << "y^x^z" << endl;
      break;
    }
    case 6: {
      cout << "y^z^x" << endl;
      break;
    }
    case 7: {
      cout << "(y^x)^z" << endl;
      break;
    }
    case 8: {
      cout << "(y^z)^x" << endl;
      break;
    }
    case 9: {
      cout << "z^x^y" << endl;
      break;
    }
    case 10: {
      cout << "z^y^x" << endl;
      break;
    }
    case 11: {
      cout << "(z^x)^y" << endl;
      break;
    }
    case 12: {
      cout << "(z^y)^x" << endl;
      break;
    }
  }
}
void solve() {
  results[0] = chain(x, y, z);
  results[1] = chain(x, z, y);
  results[2] = parenthesis(x, y, z);
  results[3] = parenthesis(x, z, y);
  results[4] = chain(y, x, z);
  results[5] = chain(y, z, x);
  results[6] = parenthesis(y, x, z);
  results[7] = parenthesis(y, z, x);
  results[8] = chain(z, x, y);
  results[9] = chain(z, y, x);
  results[10] = parenthesis(z, x, y);
  results[11] = parenthesis(z, y, x);
  m = results[0];
  idx = 1;
  for (int i = 0; i < 12; i++) {
    if (results[i] - m > 1e-16) {
      m = results[i];
      idx = i + 1;
    }
  }
  output(idx);
}
int main() {
  cin >> x >> y >> z;
  if (x <= 1 && y <= 1 && z <= 1) use_pow = 1;
  solve();
  return 0;
}
