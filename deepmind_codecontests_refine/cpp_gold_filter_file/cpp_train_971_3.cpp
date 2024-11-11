#include <bits/stdc++.h>
using namespace std;
enum Side { LEFT, RIGHT };
int main(int argc, char *argv[]) {
  int height, jump;
  cin >> height >> jump;
  cin.ignore();
  char left[height];
  char right[height];
  cin.getline(left, height + 1);
  cin.getline(right, height + 1);
  int curr_height = 0;
  queue<int> choices;
  queue<Side> sides;
  queue<int> water_level;
  vector<bool> left_visited(height);
  vector<bool> right_visited(height);
  Side side = LEFT;
  int water;
  choices.push(0);
  sides.push(LEFT);
  water_level.push(-1);
  left_visited[0] = true;
  while (!choices.empty()) {
    curr_height = choices.front();
    if (curr_height + jump >= height) {
      cout << "YES" << endl;
      return 0;
    }
    choices.pop();
    side = sides.front();
    sides.pop();
    water = water_level.front();
    water_level.pop();
    if (curr_height == water) {
      continue;
    }
    if (side == LEFT) {
      if (!right_visited[curr_height + jump] &&
          right[curr_height + jump] != 'X') {
        choices.push(curr_height + jump);
        right_visited[curr_height + jump] = true;
        sides.push(RIGHT);
        water_level.push(water + 1);
      }
      if (!left_visited[curr_height + 1] && left[curr_height + 1] != 'X') {
        choices.push(curr_height + 1);
        left_visited[curr_height + 1] = true;
        sides.push(LEFT);
        water_level.push(water + 1);
      }
      if (water < curr_height - 1 && !left_visited[curr_height - 1] &&
          left[curr_height - 1] != 'X') {
        choices.push(curr_height - 1);
        left_visited[curr_height - 1] = true;
        sides.push(LEFT);
        water_level.push(water + 1);
      }
    } else {
      if (!left_visited[curr_height + jump] &&
          left[curr_height + jump] != 'X') {
        choices.push(curr_height + jump);
        left_visited[curr_height + jump] = true;
        sides.push(LEFT);
        water_level.push(water + 1);
      }
      if (!right_visited[curr_height + 1] && right[curr_height + 1] != 'X') {
        choices.push(curr_height + 1);
        right_visited[curr_height + 1] = true;
        sides.push(RIGHT);
        water_level.push(water + 1);
      }
      if (water < curr_height - 1 && !right_visited[curr_height - 1] &&
          right[curr_height - 1] != 'X') {
        choices.push(curr_height - 1);
        right_visited[curr_height - 1] = true;
        sides.push(RIGHT);
        water_level.push(water + 1);
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
