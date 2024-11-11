#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long modd = 998244353;
vector<bool> isprime(N);
vector<int> primes;
void seive() {
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2; i <= 1e6; i++) {
    isprime[i] = true;
  }
  for (int i = 2; i * i <= 1e6; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= 1e6; j += i) {
        isprime[j] = false;
      }
    }
  }
  for (int i = 2; i < 1e6; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }
}
void Reverse_Matrix() {
  int n, k;
  cin >> n >> k;
  set<char> s;
  s.insert('a');
  s.insert('e');
  s.insert('i');
  s.insert('o');
  s.insert('u');
  int dp[3] = {0};
  for (int i = 0; i < n; i++) {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();
    int l4 = s4.length();
    int cnt1 = 0;
    for (int i = l1 - 1; i >= 0; i--) {
      if (s.find(s1[i]) != s.end()) cnt1++;
      if (cnt1 == k) {
        s1 = s1.substr(i);
        break;
      }
    }
    int cnt2 = 0;
    for (int i = l2 - 1; i >= 0; i--) {
      if (s.find(s2[i]) != s.end()) cnt2++;
      if (cnt2 == k) {
        s2 = s2.substr(i);
        break;
      }
    }
    int cnt3 = 0;
    for (int i = l3 - 1; i >= 0; i--) {
      if (s.find(s3[i]) != s.end()) cnt3++;
      if (cnt3 == k) {
        s3 = s3.substr(i);
        break;
      }
    }
    int cnt4 = 0;
    for (int i = l4 - 1; i >= 0; i--) {
      if (s.find(s4[i]) != s.end()) cnt4++;
      if (cnt4 == k) {
        s4 = s4.substr(i);
        break;
      }
    }
    if (cnt1 != k || cnt2 != k || cnt3 != k || cnt4 != k) {
      cout << "NO" << endl;
      return;
    }
    if (s1 == s2 && s2 == s3 && s3 == s4) {
      dp[0]++;
      dp[1]++;
      dp[2]++;
    } else if (s1 == s2 && s3 == s4) {
      dp[0]++;
    } else if (s1 == s3 && s2 == s4) {
      dp[1]++;
    } else if (s1 == s4 && s2 == s3) {
      dp[2]++;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  if (dp[0] < n && dp[1] < n && dp[2] < n) {
    cout << "NO";
  } else if (dp[0] == n && dp[1] == n && dp[2] == n) {
    cout << "aaaa" << endl;
  } else if (dp[0] == n) {
    cout << "aabb" << endl;
  } else if (dp[1] == n) {
    cout << "abab" << endl;
  } else {
    cout << "abba" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int TEST = 1;
  while (TEST--) {
    Reverse_Matrix();
  }
}
