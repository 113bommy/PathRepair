#include <bits/stdc++.h>
void merge(int prob[], int penalty[], int low, int mid, int high) {
  long int i, l, r, k, tempPR[50], tempPE[50];
  l = low;
  r = mid + 1;
  i = low;
  while ((l <= mid) && (r <= high)) {
    if (prob[l] > prob[r]) {
      tempPR[i] = prob[l];
      tempPE[i] = penalty[l];
      l++;
    } else if (prob[l] < prob[r]) {
      tempPR[i] = prob[r];
      tempPE[i] = penalty[l];
      r++;
    } else if (prob[l] == prob[r]) {
      if (penalty[l] <= penalty[r]) {
        tempPR[i] = prob[l];
        tempPE[i] = penalty[l];
        l++;
      } else {
        tempPR[i] = prob[r];
        tempPE[i] = penalty[r];
        r++;
      }
    }
    i++;
  }
  if (l > mid) {
    for (k = r; k <= high; k++) {
      tempPR[i] = prob[k];
      tempPE[i] = penalty[k];
      i++;
    }
  } else {
    for (k = l; k <= mid; k++) {
      tempPR[i] = prob[k];
      tempPE[i] = penalty[k];
      i++;
    }
  }
  for (k = low; k <= high; k++) {
    prob[k] = tempPR[k];
    penalty[k] = tempPE[k];
  }
}
void mergeSort(int prob[], int penalty[], int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(prob, penalty, low, mid);
    mergeSort(prob, penalty, mid + 1, high);
    merge(prob, penalty, low, mid, high);
  }
}
int main() {
  int n, k, i, counter = 1;
  scanf("%d%d", &n, &k);
  int prob[n], penalty[n];
  for (i = 0; i < n; i++) {
    scanf("%d%d", &prob[i], &penalty[i]);
  }
  mergeSort(prob, penalty, 0, n - 1);
  for (i = k - 2; i >= 0; i--) {
    if ((prob[i] == prob[k - 1]) && (penalty[i] == penalty[k - 1])) {
      counter++;
    } else
      break;
  }
  for (i = k; i < n; i++) {
    if ((prob[i] == prob[k - 1]) && (penalty[i] == penalty[k - 1])) {
      counter++;
    }
  }
  printf("%d", counter);
  return 0;
}
