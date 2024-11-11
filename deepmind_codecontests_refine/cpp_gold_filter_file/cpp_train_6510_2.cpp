#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  int64_t langval;
  map<int64_t, int64_t> lang, movies;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> langval;
    if (lang.find(langval) == lang.end()) {
      lang[langval] = 1;
    } else {
      lang[langval]++;
    }
  }
  cin >> m;
  map<int, bool> topmovies;
  int maxval = 0;
  for (i = 1; i <= m; i++) {
    cin >> langval;
    movies[i] = 0;
    if (lang.find(langval) != lang.end()) movies[i] = lang[langval];
    if (movies[i] == maxval)
      topmovies[i] = true;
    else if (movies[i] > maxval) {
      topmovies.clear();
      topmovies[i] = true;
      maxval = movies[i];
    }
  }
  movies.clear();
  maxval = 0;
  int maxindex = 1;
  for (i = 1; i <= m; i++) {
    cin >> langval;
    if (topmovies.find(i) == topmovies.end()) continue;
    movies[i] = 0;
    if (lang.find(langval) != lang.end()) movies[i] = lang[langval];
    if (movies[i] >= maxval) {
      maxindex = i;
      maxval = movies[i];
    }
  }
  cout << maxindex << endl;
  return 0;
}
