#include <bits/stdc++.h>
using namespace std;
pair<int, int> where[3000];
void swap(int i, int j) {
  pair<int, int> c;
  c = where[i];
  where[i] = where[j];
  where[j] = c;
}
int main() {
  int N;
  cin >> N;
  int num[N + 1];
  for (int i = 1; i <= N; i++) cin >> num[i];
  int arr[51][51];
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= num[i]; j++) {
      int x;
      cin >> x;
      arr[i][j] = x;
      where[x].first = i;
      where[x].second = j;
    }
  int oper = 0;
  int sum = 0;
  int result[4][3000];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= num[i]; j++) {
      if (sum + j != arr[i][j]) {
        result[0][oper] = i;
        result[1][oper] = j;
        result[2][oper] = where[sum + j].first;
        result[3][oper] = where[sum + j].second;
        oper++;
        int c = arr[i][j];
        arr[i][j] = arr[where[sum + j].first][where[sum + j].second];
        arr[where[sum + j].first][where[sum + j].second] = c;
        swap(arr[i][j], sum + j);
      }
    }
    sum += num[i];
  }
  cout << oper << endl;
  for (int i = 0; i < oper; i++) {
    for (int j = 0; j < 4; j++) cout << result[j][i] << " ";
    cout << endl;
  }
}
