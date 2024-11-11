#include <bits/stdc++.h>
using namespace std;
struct Player {
  string name;
  long int points;
  map<int, int> places;
};
Player compSecond(Player a, Player b) {
  if (a.points > b.points) {
    return a;
  } else if (a.points < b.points) {
    return b;
  }
  for (int i = 1; i < 70; i++) {
    if (a.places[i] > b.places[i]) {
      return a;
    }
    if (a.places[i] < b.places[i]) {
      return b;
    }
  }
}
Player compFirst(Player a, Player b) {
  if (a.places[1] > b.places[1]) {
    return a;
  } else if (a.places[1] < b.places[1]) {
    return b;
  }
  if (a.points > b.points) {
    return a;
  } else if (a.points < b.points) {
    return b;
  }
  for (int i = 2; i < 70; i++) {
    if (a.places[i] > b.places[i]) {
      return a;
    }
    if (a.places[i] < b.places[i]) {
      return b;
    }
  }
}
map<string, Player> parts;
vector<int> points = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
int main() {
  int n;
  cin >> n;
  set<Player> st;
  for (int i = 0; i < n; i++) {
    int players;
    cin >> players;
    for (int j = 1; j <= players; j++) {
      string name;
      cin >> name;
      parts[name].points += (j <= 10) ? points[j - 1] : 0;
      parts[name].places[j]++;
      parts[name].name = name;
    }
  }
  Player min;
  Player first;
  Player second;
  first.points = 0;
  second.points = 0;
  for (auto i : parts) {
    first = compSecond(i.second, first);
    second = compFirst(i.second, second);
  }
  cout << first.name << endl << second.name << endl;
}
