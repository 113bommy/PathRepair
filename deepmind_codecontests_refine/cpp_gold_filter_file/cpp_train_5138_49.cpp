#include <bits/stdc++.h>
using namespace std;
struct scientist {
  long long k, a, x, y, m, current_index;
  bool change;
};
struct h {
  long long value;
  int index;
};
int N;
vector<scientist> scientists;
long long k, a, x, y, m;
long long answer = 0;
vector<h> heap1;
vector<h> heap2;
h prev_result;
vector<h> result;
void add(h value, vector<h>& heap) {
  heap.push_back(value);
  int n = (int)heap.size() - 1;
  while (n > 0 && heap[(n - 1) / 2].value > heap[n].value) {
    h tmp = heap[n];
    heap[n] = heap[(n - 1) / 2];
    heap[(n - 1) / 2] = tmp;
    n = (n - 1) / 2;
  }
}
void refresh(vector<h>& heap) {
  int n = 0;
  while ((2 * n + 1 < heap.size() && heap[n].value > heap[2 * n + 1].value) ||
         (2 * n + 2 < heap.size() && heap[n].value > heap[2 * n + 2].value)) {
    if (2 * n + 1 < heap.size() && heap[n].value > heap[2 * n + 1].value) {
      h tmp = heap[n];
      heap[n] = heap[2 * n + 1];
      heap[2 * n + 1] = tmp;
      n = 2 * n + 1;
    } else {
      h tmp = heap[n];
      heap[n] = heap[2 * n + 2];
      heap[2 * n + 2] = tmp;
      n = 2 * n + 2;
    }
  }
}
int main(int argc, const char* argv[]) {
  cin >> N;
  int max = 0;
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> k >> a >> x >> y >> m;
    scientists.push_back({k, a, x, y, m, 0, false});
    int res = 0;
    for (int j = 1; j < k; ++j) {
      long long new_a = (a * x + y) % m;
      if (new_a < a) {
        res++;
      }
      a = new_a;
    }
    if (max < res) max = res;
    sum += k;
  }
  cout << max << endl;
  if (sum > 200000) {
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    add({scientists[i].a, i}, heap1);
    if (scientists[i].current_index < scientists[i].k) {
      long long new_a = (scientists[i].a * scientists[i].x + scientists[i].y) %
                        scientists[i].m;
      if (new_a < scientists[i].a)
        scientists[i].change = true;
      else
        scientists[i].change = false;
      scientists[i].a = new_a;
      scientists[i].current_index++;
    }
  }
  prev_result = {-1, -1};
  while (heap1.size() > 0) {
    while (heap1.size() > 0) {
      h t = heap1[0];
      heap1[0] = heap1.back();
      heap1.pop_back();
      if (result.size() <= 200000) {
        result.push_back({t.value, t.index + 1});
      }
      if (prev_result.index != -1) {
        if (prev_result.value > t.value) answer++;
      }
      prev_result = {t.value, t.index + 1};
      refresh(heap1);
      if (scientists[t.index].change) {
        if (scientists[t.index].current_index < scientists[t.index].k) {
          add({scientists[t.index].a, t.index}, heap2);
          long long new_a = (scientists[t.index].a * scientists[t.index].x +
                             scientists[t.index].y) %
                            scientists[t.index].m;
          if (new_a < scientists[t.index].a)
            scientists[t.index].change = true;
          else
            scientists[t.index].change = false;
          scientists[t.index].a = new_a;
          scientists[t.index].current_index++;
        }
      } else {
        if (scientists[t.index].current_index < scientists[t.index].k) {
          add({scientists[t.index].a, t.index}, heap1);
          long long new_a = (scientists[t.index].a * scientists[t.index].x +
                             scientists[t.index].y) %
                            scientists[t.index].m;
          if (new_a < scientists[t.index].a)
            scientists[t.index].change = true;
          else
            scientists[t.index].change = false;
          scientists[t.index].a = new_a;
          scientists[t.index].current_index++;
        }
      }
    }
    while (heap2.size() > 0) {
      h t = heap2[0];
      heap2[0] = heap2.back();
      heap2.pop_back();
      if (result.size() <= 200000) {
        result.push_back({t.value, t.index + 1});
      }
      if (prev_result.index != -1) {
        if (prev_result.value > t.value) answer++;
      }
      prev_result = {t.value, t.index + 1};
      refresh(heap2);
      if (scientists[t.index].change) {
        if (scientists[t.index].current_index < scientists[t.index].k) {
          add({scientists[t.index].a, t.index}, heap1);
          long long new_a = (scientists[t.index].a * scientists[t.index].x +
                             scientists[t.index].y) %
                            scientists[t.index].m;
          if (new_a < scientists[t.index].a)
            scientists[t.index].change = true;
          else
            scientists[t.index].change = false;
          scientists[t.index].a = new_a;
          scientists[t.index].current_index++;
        }
      } else {
        if (scientists[t.index].current_index < scientists[t.index].k) {
          add({scientists[t.index].a, t.index}, heap2);
          long long new_a = (scientists[t.index].a * scientists[t.index].x +
                             scientists[t.index].y) %
                            scientists[t.index].m;
          if (new_a < scientists[t.index].a)
            scientists[t.index].change = true;
          else
            scientists[t.index].change = false;
          scientists[t.index].a = new_a;
          scientists[t.index].current_index++;
        }
      }
    }
  }
  if (result.size() <= 200000) {
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i].value << " " << result[i].index << endl;
    }
  }
  return 0;
}
