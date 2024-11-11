#include <bits/stdc++.h>
using namespace std;
void number_of_brackets(string& brackets, vector<int>& opened,
                        vector<int>& closed, vector<int>& difference);
int get_depth(vector<int>& difference);
void create_output_matrix(string& brackets, vector<int>& difference);
void get_spaces(string& brackets, list<int>& spaces);
int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  string brackets;
  cin >> brackets;
  vector<int> opened(brackets.length(), 0);
  vector<int> closed(brackets.length(), 0);
  vector<int> difference(brackets.length(), 0);
  number_of_brackets(brackets, opened, closed, difference);
  create_output_matrix(brackets, difference);
  return 0;
}
void number_of_brackets(string& brackets, vector<int>& opened,
                        vector<int>& closed, vector<int>& difference) {
  int count_opened = 0;
  int count_closed = 0;
  for (int i = 0; i < brackets.length(); i++) {
    if (brackets[i] == '[') {
      count_opened++;
    } else if (brackets[i] == ']') {
      count_closed++;
    }
    opened[i] = count_opened;
    closed[i] = count_closed;
    difference[i] = opened[i] - closed[i];
  }
}
int get_depth(vector<int>& difference) {
  int Depth = difference[0];
  for (int i = 1; i < difference.size(); i++) {
    if (difference[i] > Depth) {
      Depth = difference[i];
    }
  }
  return Depth;
}
void create_output_matrix(string& brackets, vector<int>& difference) {
  int depth = get_depth(difference);
  list<int> spaces;
  get_spaces(brackets, spaces);
  int height = 2 * depth + 1;
  int width = brackets.length() + 3 * spaces.size();
  char** output_matrix = new char*[height];
  for (int i = 0; i < height; i++) {
    output_matrix[i] = new char[width];
    for (int j = 0; j < width; j++) {
      output_matrix[i][j] = ' ';
    }
  }
  int current_column = 0;
  int current_depth = 0;
  for (int current_bracket = 0; current_bracket < brackets.size();
       current_bracket++) {
    if (brackets[current_bracket] == ']') {
      current_depth--;
    }
    if (current_bracket == *spaces.begin()) {
      current_column += 3;
      spaces.pop_front();
    }
    int top_idx = current_depth;
    int bottom_idx = height - current_depth - 1;
    output_matrix[top_idx][current_column] = '+';
    output_matrix[bottom_idx][current_column] = '+';
    for (int current_row = 0; current_row < height; current_row++) {
      if (current_row > top_idx && current_row < bottom_idx) {
        output_matrix[current_row][current_column] = '|';
      }
      if (current_row == top_idx || current_row == bottom_idx) {
        output_matrix[current_row][current_column] = '+';
      }
    }
    if (brackets[current_bracket] == '[') {
      output_matrix[top_idx][current_column + 1] = '-';
      output_matrix[bottom_idx][current_column + 1] = '-';
    } else {
      output_matrix[top_idx][current_column - 1] = '-';
      output_matrix[bottom_idx][current_column - 1] = '-';
    }
    current_depth = difference[current_bracket];
    current_column++;
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << output_matrix[i][j];
    }
    cout << endl;
  }
  for (int i = 0; i < height; i++) {
    delete[] output_matrix[i];
  }
  delete[] output_matrix;
}
void get_spaces(string& brackets, list<int>& spaces) {
  for (int i = 0; i < brackets.length(); i++) {
    if (brackets[i] == ']' && brackets[i - 1] == '[') {
      spaces.push_back(i);
    }
  }
}
