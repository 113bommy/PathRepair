#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long N, PL, PR;
  string L, R;
  vector<vector<long>> CL, CR;
  vector<pair<long, long>> Answer;
  cin >> N;
  cin.clear();
  cin.ignore(32767, '\n');
  getline(cin, L);
  getline(cin, R);
  L = '$' + L + '$';
  R = '$' + R + '$';
  CL.resize(256);
  CR.resize(256);
  for (long i = 1; i <= N; ++i) {
    CL[L[i]].push_back(i);
    CR[R[i]].push_back(i);
  }
  for (long i = 'a'; i <= 'z'; ++i) {
    long M = min(CL[i].size(), CR[i].size());
    for (long j = 0; j < M; ++j) Answer.push_back({CL[i][j], CR[i][j]});
    for (long j = M; j < CL[i].size(); ++j) CL['T'].push_back(CL[i][j]);
    for (long j = M; j < CR[i].size(); ++j) CR['T'].push_back(CR[i][j]);
  }
  PR = min(CL['T'].size(), CR['?'].size());
  for (long i = 0; i < PR; ++i) Answer.push_back({CL['T'][i], CR['?'][i]});
  PL = min(CR['T'].size(), CL['?'].size());
  for (long i = 0; i < PL; ++i) Answer.push_back({CR['T'][i], CL['?'][i]});
  for (; PL < CL['?'].size() && PR < CR['?'].size(); ++PL, ++PR)
    Answer.push_back({CL['?'][PL], CR['?'][PR]});
  cout << Answer.size() << endl;
  for (long i = 0; i < Answer.size(); ++i)
    cout << Answer[i].first << ' ' << Answer[i].second << endl;
  return 0;
}
