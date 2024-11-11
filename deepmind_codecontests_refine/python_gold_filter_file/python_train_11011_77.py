from itertools import accumulate

n, k = map(int,input().split())

a = list(map(int,input().split()))

for j in range(k):
    if j > 41:
        break

    b = [0] * n

    for i in range(n):
        b[max(0, i - a[i])] += 1
        
        if i + a[i] + 1 < n:
            b[i + a[i] + 1] -= 1

    a = list(accumulate(b))

print(*a)