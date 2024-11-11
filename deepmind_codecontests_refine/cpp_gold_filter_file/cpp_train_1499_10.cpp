#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int> > input;
map<string, int> db;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    int score;
    cin >> name >> score;
    input.push_back(pair<string, int>(name, score));
  }
  for (int i = 0; i < n; i++) {
    string name = input[i].first;
    int score = input[i].second;
    if (db.find(name) == db.end()) db[name] = 0;
    db[name] += score;
  }
  int best_score = 0;
  for (map<string, int>::iterator mit = db.begin(); mit != db.end(); mit++)
    if (mit->second > best_score) best_score = mit->second;
  set<string> bests;
  for (map<string, int>::iterator mit = db.begin(); mit != db.end(); mit++)
    if (mit->second == best_score) bests.insert(mit->first);
  db.clear();
  for (int i = 0; i < n; i++) {
    string name = input[i].first;
    int score = input[i].second;
    if (db.find(name) == db.end()) db[name] = 0;
    db[name] += score;
    if (db[name] >= best_score && bests.find(name) != bests.end()) {
      cout << name << endl;
      return 0;
    }
  }
  return 0;
}
