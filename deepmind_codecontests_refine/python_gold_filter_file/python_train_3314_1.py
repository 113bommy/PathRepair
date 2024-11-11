from collections import Counter

n, k = map(int, input().split())
A = sorted(Counter(list(map(int, input().split()))).most_common(), key=lambda x:x[1])
cnt = 0
if len(A) > k:
    for i in range(len(A)-k):
        cnt += A[i][1]
print(cnt)