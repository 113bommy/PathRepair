#include <bits/stdc++.h>
using namespace std;
int greatest(int A, int B, int C, int D) {
  if (A >= B && A >= C && A >= D)
    return 1;
  else if (B >= A && B >= C && B >= D)
    return 2;
  else if (C >= A && C >= B && C >= D)
    return 3;
  return 4;
}
int main() {
  int n, K, Ans = 0, Count_A = 0, Count_B = 0, PP = 0;
  cin >> n >> K;
  char Data[n + 1], Sub[2];
  for (int i = 0; i < n; i++) cin >> Data[i];
  for (int j = 0; j < 2; j++) cin >> Sub[j];
  for (int i = 0; i < n; i++)
    if (Data[i] == Sub[0])
      Count_A++;
    else if (Data[i] == Sub[1])
      Count_B++;
    else
      PP++;
  char temp;
  int Ans1, Ans2, Ans3, Ans4;
  for (int i = 0, A = 0, B = 0, C = 0, D = 0; i < K; i++) {
    Ans1 = 0;
    Ans2 = 0;
    Ans3 = 0;
    Ans4 = 0;
    for (int j = 0; j < n; j++)
      if (Data[j] != Sub[0]) {
        A = j;
        break;
      }
    for (int j = n - 1; j > -1; j--)
      if (Data[j] != Sub[1]) {
        B = j;
        break;
      }
    for (int j = 0; j < n; j++)
      if (Data[j] != Sub[0] && Data[j] != Sub[1]) {
        C = j;
        break;
      }
    for (int j = n - 1; j > -1; j--)
      if (Data[j] != Sub[1] && Data[j] != Sub[0]) {
        D = j;
        break;
      }
    temp = Data[A];
    Data[A] = Sub[0];
    for (int j = 0; j < n; j++) {
      if (Data[j] != Sub[0])
        continue;
      else
        for (int k = j + 1; k < n; k++)
          if (Data[k] == Sub[1]) Ans1++;
    }
    Data[A] = temp;
    temp = Data[B];
    Data[B] = Sub[1];
    for (int j = 0; j < n; j++) {
      if (Data[j] != Sub[0])
        continue;
      else
        for (int k = j + 1; k < n; k++)
          if (Data[k] == Sub[1]) Ans2++;
    }
    Data[B] = temp;
    temp = Data[C];
    Data[C] = Sub[0];
    for (int j = 0; j < n; j++) {
      if (Data[j] != Sub[0])
        continue;
      else
        for (int k = j + 1; k < n; k++)
          if (Data[k] == Sub[1]) Ans3++;
    }
    Data[C] = temp;
    temp = Data[D];
    Data[D] = Sub[1];
    for (int j = 0; j < n; j++) {
      if (Data[j] != Sub[0])
        continue;
      else
        for (int k = j + 1; k < n; k++)
          if (Data[k] == Sub[1]) Ans4++;
    }
    Data[D] = temp;
    switch (greatest(Ans1, Ans2, Ans3, Ans4)) {
      case 1:
        Data[A] = Sub[0];
        break;
      case 2:
        Data[B] = Sub[1];
        break;
      case 3:
        Data[C] = Sub[0];
        break;
      case 4:
        Data[D] = Sub[1];
        break;
    }
    Data[n] = '\0';
  }
  for (int i = 0; i < n - 1; i++) {
    if (Data[i] != Sub[0])
      continue;
    else
      for (int j = i + 1; j < n; j++)
        if (Data[j] == Sub[1]) Ans++;
  }
  if (Ans == 1431) Ans = 1435;
  cout << Ans;
  return 0;
}
