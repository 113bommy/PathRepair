#include <bits/stdc++.h>
using namespace std;
long long answer(vector<vector<char> > b1, vector<vector<char> > b2,
                 vector<vector<char> > b3, vector<vector<char> > b4,
                 vector<vector<char> > config1, vector<vector<char> > config2,
                 long long N) {
  long long ans = 0;
  for (long long i = 0; i < N; i++) {
    for (long long j = 0; j < N; j++) {
      if (b1[i][j] != config1[i][j]) ans = ans + 1;
      if (b2[i][j] != config1[i][j]) ans = ans + 1;
      if (b3[i][j] != config2[i][j]) ans = ans + 1;
      if (b4[i][j] != config2[i][j]) ans = ans + 1;
    }
  }
  return ans;
}
int main() {
  long long N;
  cin >> N;
  vector<vector<char> > b1;
  char color;
  for (long long i = 0; i < N; i++) {
    vector<char> temp;
    for (long long j = 0; j < N; j++) {
      cin >> color;
      temp.push_back(color);
    }
    b1.push_back(temp);
  }
  vector<vector<char> > b2;
  for (long long i = 0; i < N; i++) {
    vector<char> temp;
    for (long long j = 0; j < N; j++) {
      cin >> color;
      temp.push_back(color);
    }
    b2.push_back(temp);
  }
  vector<vector<char> > b3;
  for (long long i = 0; i < N; i++) {
    vector<char> temp;
    for (long long j = 0; j < N; j++) {
      cin >> color;
      temp.push_back(color);
    }
    b3.push_back(temp);
  }
  vector<vector<char> > b4;
  for (long long i = 0; i < N; i++) {
    vector<char> temp;
    for (long long j = 0; j < N; j++) {
      cin >> color;
      temp.push_back(color);
    }
    b4.push_back(temp);
  }
  vector<vector<char> > config1, config2;
  for (long long i = 0; i < N; i++) {
    vector<char> temp1, temp2;
    for (long long j = 0; j < N; j++) {
      if ((i + j) % 2 == 0) {
        temp1.push_back('1');
        temp2.push_back('0');
      } else {
        temp1.push_back('0');
        temp2.push_back('1');
      }
    }
    config1.push_back(temp1);
    config2.push_back(temp2);
  }
  long long finalans = N * N * N;
  finalans = min(finalans, answer(b1, b2, b3, b4, config1, config2, N));
  finalans = min(finalans, answer(b1, b3, b2, b4, config1, config2, N));
  finalans = min(finalans, answer(b1, b4, b2, b3, config1, config2, N));
  finalans = min(finalans, answer(b1, b2, b3, b4, config2, config1, N));
  finalans = min(finalans, answer(b1, b3, b2, b4, config2, config1, N));
  finalans = min(finalans, answer(b1, b4, b2, b3, config2, config1, N));
  cout << finalans << endl;
}
