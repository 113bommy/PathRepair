#include <bits/stdc++.h>
int main() {
  long requests, time[100000], i, j, server_id[100];
  short available[100000], servers, server_req[100000], help = 0, sum = 0,
                                                        duration[100000];
  scanf("%hu", &servers);
  scanf("%li", &requests);
  for (i = 0; i < servers; i++) {
    server_id[i] = 0;
  }
  for (i = 0; i < requests; i++) {
    scanf("%li", &time[i]);
    scanf("%hu", &server_req[i]);
    scanf("%hu", &duration[i]);
    available[i] = 0;
  }
  for (i = 0; i < requests; i++) {
    for (j = i; time[i] + duration[i] > time[j]; j++) {
      available[j] += server_req[i];
    }
    if (available[i] <= servers) {
      for (j = 0; help < server_req[i]; j++) {
        if (server_id[j] <= time[i]) {
          sum += j + 1;
          server_id[j] = time[i] + duration[i];
          help++;
        }
      }
      printf("%hu \n", sum);
      help = 0;
      sum = 0;
    } else {
      for (j = i; time[i] + duration[i] > time[j]; j++) {
        available[j] += server_req[i];
      }
      printf("-1 \n");
    }
  }
  return 0;
}
