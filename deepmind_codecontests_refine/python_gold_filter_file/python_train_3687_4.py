n, k = map(int, input().split())
a = list(map(int, input().split()))
start_job = 1
min_hate = 1000 * n + 1
for i in range(k):
  hate = sum(a[i::k])
  if hate < min_hate:
    start_job = i + 1
    min_hate = hate
print(start_job)