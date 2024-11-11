#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string b;
  unordered_map<string, int> wordFreq;
  int max = 0;
  string result;
  for (int i = 0; i < n; i++) {
    b += s[i];
    b += s[i + 1];
    b += " ";
  }
  stringstream a(b);
  string word;
  while (a >> word) {
    wordFreq[word]++;
    if (max < wordFreq[word]) {
      max = wordFreq[word];
      result = word;
    }
  }
  cout << result;
}
