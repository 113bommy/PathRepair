#include <bits/stdc++.h>
using namespace std;
int main() {
  int digitsOcc1[10], digitsOcc2[10], arr[10];
  int n, start1 = -1, start2 = -1;
  int index1 = 0, index2 = 0;
  bool flag1 = false, flag2 = false;
  string num, p1 = "", p2 = "";
  cin >> num;
  n = num.size();
  memset(digitsOcc1, 0, sizeof(digitsOcc1));
  for (int i = 0; i < n; i++) digitsOcc1[((int)num[i]) - 48]++;
  memcpy(digitsOcc2, digitsOcc1, sizeof(digitsOcc1));
  for (int i = 0; i < 10; i++) {
    arr[i] = min(digitsOcc1[i], digitsOcc1[9 - i]);
  }
  for (int i = 1; i < 6; i++) {
    if ((digitsOcc1[i] - arr[i]) && (digitsOcc1[10 - i] - arr[10 - i])) {
      flag1 = flag2 = true;
      start1 = i;
      start2 = 10 - i;
      break;
    }
  }
  if (start1 == -1) {
    for (int i = 1; i < 6; i++) {
      if (digitsOcc1[i] && digitsOcc1[10 - i]) {
        start1 = i;
        start2 = 10 - i;
        flag1 = (digitsOcc1[i] - arr[i]);
        flag2 = (digitsOcc1[10 - i] - arr[10 - i]);
        if (flag1 || flag2) break;
      }
    }
  }
  for (int j = 0; j < digitsOcc1[0] - arr[0]; j++) {
    p1 += ((char)(48));
  }
  for (int j = 0; j < digitsOcc2[0] - arr[9]; j++) {
    p2 += ((char)(48));
  }
  index1 = p1.size();
  for (int i = 0; i < 10; i++) {
    digitsOcc1[i] -= arr[i];
    digitsOcc2[9 - i] -= arr[i];
    for (int j = 0; j < arr[i]; j++) {
      p1 += ((char)(i + 48));
      p2 += ((char)(9 - i + 48));
    }
  }
  index2 = p1.size();
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < digitsOcc1[i]; j++) {
      p1 += ((char)(i + 48));
    }
  }
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < digitsOcc2[i]; j++) {
      p2 += ((char)(i + 48));
    }
  }
  if (start1 != -1) {
    if (flag1 && flag2) {
      int start1Index = p1.rfind((char)(start1 + 48));
      int start2Index = p2.rfind((char)(start2 + 48));
      p1.erase(start1Index, 1);
      p2.erase(start2Index, 1);
      p1.insert(p1.begin() + index1, (char)(start1 + 48));
      p2.insert(p2.begin() + index1, (char)(start2 + 48));
    } else if (flag1) {
      int start1Index = p1.rfind((char)(start1 + 48));
      int start2Index = p2.find((char)(start2 + 48));
      swap(p1[start1Index], p1[start2Index]);
      p1.erase(start2Index, 1);
      p2.erase(start2Index, 1);
      p1.insert(p1.begin() + index1, (char)(start1 + 48));
      p2.insert(p2.begin() + index1, (char)(start2 + 48));
    } else if (flag2) {
      int start1Index = p1.find((char)(start1 + 48));
      int start2Index = p2.rfind((char)(start2 + 48));
      swap(p2[start1Index], p2[start2Index]);
      p1.erase(start1Index, 1);
      p2.erase(start1Index, 1);
      p1.insert(p1.begin() + index1, (char)(start1 + 48));
      p2.insert(p2.begin() + index1, (char)(start2 + 48));
    } else {
      int start1Index = p1.find((char)(start1 + 48));
      int start2Index = p2.find((char)(start2 + 48));
      swap(p1[start1Index], p1[start2Index]);
      p1.erase(start2Index, 1);
      p2.erase(start2Index, 1);
      p1.insert(p1.begin() + index1, (char)(start1 + 48));
      p2.insert(p2.begin() + index1, (char)(start2 + 48));
      char temp1 = p1[start1Index];
      char temp2 = p2[start1Index];
      p1.erase(start1Index, 1);
      p2.erase(start1Index, 1);
      p1 += temp1;
      p2 += temp2;
    }
  }
  reverse(p1.begin(), p1.end());
  reverse(p2.begin(), p2.end());
  cout << p1 << endl;
  cout << p2 << endl;
  return 0;
}
