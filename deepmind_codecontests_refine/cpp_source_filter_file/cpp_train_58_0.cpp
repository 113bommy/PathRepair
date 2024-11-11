#include <bits/stdc++.h>
using namespace std;
const int MAXN = 128;
int ar[MAXN], N, M, id;
char command[30];
void alloc() {
  int k, bos;
  cin >> k;
  for (int i = 1; i <= M; i++) {
    if (!ar[i])
      bos++;
    else
      bos = 0;
    if (bos == k) {
      id++;
      for (int j = i - bos + 1; j <= i; j++) ar[j] = id;
      cout << id << endl;
      return;
    }
  }
  cout << "NULL" << endl;
}
void erase() {
  int k, flag = 1;
  cin >> k;
  for (int i = 1; i <= M; i++)
    if (ar[i] == k) {
      ar[i] = 0;
      flag = 0;
    }
  if (flag && k != 0) cout << "ILLEGAL_ERASE_ARGUMENT\n";
}
void defragment() {
  int place = 1;
  for (int i = 1; i <= M; i++)
    if (ar[i]) ar[place++] = ar[i];
  for (int i = place; i <= M; i++) ar[i] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> command;
    if (command[0] == 'a') alloc();
    if (command[0] == 'e') erase();
    if (command[0] == 'd') defragment();
  }
  return 0;
}
