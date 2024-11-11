#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int arr[100000];
  cin >> a >> b >> c;
  arr[a]++;
  arr[b]++;
  arr[c]++;
  bool paisi = false;
  if (arr[1])
    paisi = true;
  else if (arr[2] >= 2)
    paisi = true;
  else if (arr[3] >= 3)
    paisi = true;
  else if (arr[4] == 2 && arr[2])
    paisi = true;
  if (paisi)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
