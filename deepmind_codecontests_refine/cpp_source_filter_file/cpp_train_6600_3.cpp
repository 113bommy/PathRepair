#include <bits/stdc++.h>
using namespace std;
long long int strtoint(string s) {
  stringstream ss;
  ss << s;
  long long int y;
  ss >> y;
  return y;
}
string intostr(long long int a) {
  stringstream ss;
  ss << a;
  string s;
  ss >> s;
  return s;
}
long long int largest(vector<long long int> &arr) {
  long long int maxi = INT_MIN;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > maxi) maxi = arr[i];
  }
  return maxi;
}
long long int smallest(vector<long long int> &arr) {
  long long int maxi = INT_MAX;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < maxi) maxi = arr[i];
  }
  return maxi;
}
long long int True[101][101];
long long int False[101][101];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int w, x, y, z;
  cin >> w >> x >> y >> z;
  if (w * z / y <= x) {
    int total = w * x;
    int usednum = w * (w * z);
    int usedden = y;
    int Num = (total * y - usednum);
    int Den = y * total;
    int pop = gcd(int(Num), int(Den));
    Num = Num / pop;
    Den = Den / pop;
    cout << Num << "/" << Den << endl;
  } else {
    int total = w * x;
    int usednum = x * (y * x);
    int usedden = z;
    int Num = total * z - usednum;
    int Den = total * z;
    int pop = gcd(Num, Den);
    Num = Num / pop;
    Den = Den / pop;
    cout << Num << "/" << Den << endl;
  }
  return 0;
}
