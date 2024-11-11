#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
bool karn(string x, string y) { return mp[x] < mp[y]; }
int distancee(int x, int y) {
  if (x > y)
    return 12 - x + y;
  else
    return y - x;
}
int main() {
  int cnt1 = 0, cnt2 = 0;
  mp["C"] = 0;
  mp["C#"] = 1;
  mp["D"] = 2;
  mp["D#"] = 3;
  mp["E"] = 4;
  mp["F"] = 5;
  mp["F#"] = 6;
  mp["G"] = 7;
  mp["G#"] = 8;
  mp["A"] = 9;
  mp["B"] = 10;
  mp["H"] = 11;
  string arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr, arr + 3, karn);
  if (distancee(mp[arr[0]], mp[arr[1]]) == 4 &&
      distancee(mp[arr[1]], mp[arr[2]]) == 3) {
    cout << "major" << endl;
  } else if (distancee(mp[arr[2]], mp[arr[0]]) == 4 &&
             distancee(mp[arr[0]], mp[arr[1]]) == 3) {
    cout << "major" << endl;
  } else if (distancee(mp[arr[1]], mp[arr[2]]) == 4 &&
             distancee(mp[arr[2]], mp[arr[0]]) == 3) {
    cout << "major" << endl;
  } else if (distancee(mp[arr[0]], mp[arr[1]]) == 3 &&
             distancee(mp[arr[1]], mp[arr[2]]) == 4) {
    cout << "minor" << endl;
  } else if (distancee(mp[arr[2]], mp[arr[0]]) == 3 &&
             distancee(mp[arr[0]], mp[arr[1]]) == 4) {
    cout << "minor" << endl;
  } else if (distancee(mp[arr[1]], mp[arr[2]]) == 3 &&
             distancee(mp[arr[2]], mp[arr[0]]) == 4) {
    cout << "minor" << endl;
  } else {
    cout << "strange" << endl;
  }
  return 0;
}
