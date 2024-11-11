#include <bits/stdc++.h>
using namespace std;
int N, answer;
int inflorescence[100000 + 5];
int apple[100000 + 5];
int dropTime[100000 + 5];
void solution1() {
  for (int i = 1; i <= N; i++) apple[i] = 1;
  int counter = N;
  while (counter) {
    if (1) {
      for (int i = 1; i <= N; i++) cout << apple[i] << " ";
      cout << endl;
    }
    answer += apple[1];
    counter -= apple[1];
    apple[1] = 0;
    for (int i = 2; i <= N; i++) {
      apple[inflorescence[i]] += apple[i];
      counter -= apple[inflorescence[i]] / 2 * 2;
      apple[inflorescence[i]] %= 2;
      apple[i] = 0;
    }
  }
}
void solution2() {
  dropTime[1] = 1;
  for (int i = 2; i <= N; i++) {
    dropTime[i] = dropTime[inflorescence[i]] + 1;
    if (1) cout << dropTime[i] << " ";
  }
  if (1) cout << endl;
  for (int i = 1; i <= N; i++) {
    apple[dropTime[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    answer += apple[i] % 2;
  }
}
int main() {
  cin >> N;
  inflorescence[1] = 1;
  for (int i = 2; i <= N; i++) cin >> inflorescence[i];
  solution2();
  cout << answer << endl;
  return 0;
}
