#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int numCitiesCand[200];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  int numCandidates, numCities;
  cin >> numCandidates >> numCities;
  for (int(i) = 0, j123 = numCities; (i) < j123; (i)++) {
    int topCandidate = 0;
    long long topVotes = 0;
    for (int(j) = 1, j123 = numCandidates; (j) <= j123; (j)++) {
      long long foo;
      cin >> foo;
      if (foo > topVotes) {
        topVotes = foo;
        topCandidate = j;
      }
    }
    numCitiesCand[topCandidate]++;
  }
  int topCandidate = 0;
  int topNumCities = 0;
  for (int(i) = 1, j123 = numCandidates; (i) <= j123; (i)++) {
    if (numCitiesCand[i] > topNumCities) {
      topNumCities = numCitiesCand[i];
      topCandidate = i;
    }
  }
  cout << topCandidate << '\n';
}
