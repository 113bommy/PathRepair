#include <bits/stdc++.h>
using namespace std;
void makeKth(const int& n, const int& l, const int& k, queue<char>& letters,
             vector<string>& results, const int& startIndex) {
  for (int i = startIndex; i <= k; i++) {
    results[i] += letters.front();
    letters.pop();
  }
  int j;
  for (j = k; j > startIndex; j--) {
    if (j == 1 || results[j - 1] != results[j]) {
      break;
    }
  }
  if (results[k].size() == l) {
    for (int i = 1; i <= n; i++) {
      while (results[i].size() < l) {
        results[i] += letters.front();
        letters.pop();
      }
    }
  } else {
    makeKth(n, l, k, letters, results, j);
  }
  return;
}
int main() {
  queue<char> letters;
  vector<string> results;
  int n, l, k;
  cin >> n >> l >> k;
  vector<char> letters_temp;
  letters_temp.reserve(n * l);
  char next;
  cin >> next;
  while (!cin.eof()) {
    letters_temp.push_back(next);
    cin >> next;
  }
  results.reserve(n + 1);
  for (int i = 0; i < n + 1; i++) {
    results.push_back("");
  }
  sort(letters_temp.begin(), letters_temp.end());
  for (int i = 0; i < letters_temp.size(); i++) {
    letters.push(letters_temp[i]);
  }
  makeKth(n, l, k, letters, results, 1);
  for (int i = 1; i < results.size(); i++) {
    cout << results[i] << endl;
  }
  return 0;
}
