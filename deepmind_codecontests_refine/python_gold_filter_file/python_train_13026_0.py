n,k=map(int,input().split())
A = list(map(int, input().split()))

B = [0]*n
for i in range(n):
    B[i] = i%k
B = [b+1 for b in B]
#print(B)
from collections import Counter
C = Counter(A)
cur= 0
X = []
d = {}
j = 0
for key, v in C.items():
    if v > k:
        print('NO')
        exit()
    d[key] = j
    X.append(B[cur:cur+v])
    j += 1
    cur += v
ans = [0]*n
for i, a in enumerate(A):
    ans[i] = X[d[a]].pop()
print('YES')
print(*ans)
