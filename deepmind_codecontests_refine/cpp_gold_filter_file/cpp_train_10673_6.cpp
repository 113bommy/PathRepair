#include <bits/stdc++.h>
using namespace std;
int arr[5001], visited[5001], answer[5001];
int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    int Max = 0, color = 0;
    memset(visited, 0, sizeof visited);
    for (int j = i; j < n; j++) {
      visited[arr[j]]++;
      if (visited[arr[j]] > Max || (visited[arr[j]] == Max && color >= arr[j]))
        Max = visited[arr[j]], color = arr[j];
      answer[color]++;
    }
  }
  for (int i = 1; i <= n; i++) cout << answer[i] << " ";
  cout << "\n";
  return 0;
}
