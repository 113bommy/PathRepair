#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5;
const long long temp = 15;
long long visited[N];
int32_t main() {
  long long k;
  cin >> k;
  string input;
  cin >> input;
  long long n = input.size();
  long long s = 0;
  long long e = n - 1;
  while (s <= e) {
    if (input[s] == '?' and input[e] == '?') {
    } else if (input[s] != '?' and input[e] == '?') {
      input[e] = input[s];
      visited[input[e]]++;
    } else if (input[s] == '?' and input[e] != '?') {
      input[s] = input[e];
      visited[input[s]]++;
    } else if (input[s] != input[e]) {
      cout << "IMPOSSIBLE";
      return 0;
    } else {
      visited[input[s]]++;
    }
    s++;
    e--;
  }
  s = n / 2;
  if (n % 2 == 0) s--;
  e = n - 1;
  vector<char> v;
  long long i = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (visited[ch] == 0 and i < k) {
      v.push_back(ch);
    }
    i++;
  }
  reverse(v.begin(), v.end());
  vector<char> temp = v;
  reverse(v.begin(), v.end());
  string input1 = input;
  while (s >= 0) {
    long long e = n - 1 - s;
    if (s == e and input[s] == '?') {
      if (v.size() == 0) {
        input[s] = 'a';
        input[e] = 'a';
      } else {
        input[s] = v.back();
        input[e] = v.back();
        v.pop_back();
      }
    } else if (input[s] == '?') {
      if (v.size() == 0) {
        input[s] = 'a';
        input[e] = 'a';
      } else {
        input[s] = v.back();
        input[e] = v.back();
        v.pop_back();
      }
    }
    s--;
  }
  if (v.size() != 0) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  s = 0;
  e = n - 1;
  v = temp;
  while (s <= e) {
    if (s == e and input1[s] == '?') {
      if (v.size() == 0) {
        input1[s] = 'a';
        input1[e] = 'a';
        break;
      }
      input1[s] = v.back();
      input1[e] = v.back();
      v.pop_back();
    }
    if (input1[s] == '?') {
      if (v.size() == 0) {
        input1[s] = 'a';
        input1[e] = 'a';
      } else {
        input1[s] = v.back();
        input1[e] = v.back();
        v.pop_back();
      }
    }
    s++;
    e--;
  }
  cout << min(input1, input);
}
