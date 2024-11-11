#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int arrDef[1000];
int arrOff[1000];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  int def = 0;
  int off = 0;
  int temp;
  cin >> temp;
  cin >> n;
  for (int i = 0; i < temp; i++) {
    string x;
    cin >> x;
    if (x[0] == 'A') {
      cin >> arrOff[off];
      off++;
    } else {
      cin >> arrDef[def];
      def++;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end());
  sort(arrDef, arrDef + def);
  sort(arrOff, arrOff + off);
  int best = 0;
  temp = 0;
  reverse(arr.begin(), arr.end());
  int who = 0;
  for (int i = 0; i < n; i++) {
    while (who < off && arrOff[who] > arr[i]) {
      who++;
    }
    if (who < off) {
      temp += arr[i] - arrOff[who];
      who++;
    }
  }
  best = max(best, temp);
  temp = 0;
  sort(arr.begin(), arr.end());
  bool fail = false;
  for (int i = 0; i < def; i++) {
    who = -1;
    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] > arrDef[i]) {
        who = j;
        break;
      }
    }
    if (who == -1) {
      fail = true;
      break;
    } else {
      swap(arr[who], arr[arr.size() - 1]);
      arr.pop_back();
      sort(arr.begin(), arr.end());
    }
  }
  for (int i = 0; i < arr.size(); i++) {
    temp += arr[i];
  }
  for (int i = 0; i < off; i++) {
    temp -= arrOff[i];
  }
  for (int i = 0; i < off; i++) {
    who = -1;
    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] > arrOff[i]) {
        who = j;
        break;
      }
    }
    if (who == -1) {
      fail = true;
      break;
    } else {
      swap(arr[who], arr[arr.size() - 1]);
      arr.pop_back();
      sort(arr.begin(), arr.end());
    }
  }
  if (!fail) best = max(best, temp);
  cout << best << "\n";
  return 0;
}
