from math import ceil

n, s = list(map(int, input().split()))
A = list(map(int, input().split()))
if sum(A) < s:
    print(-1)
else:
    x = min(A)
    y = 0
    for k in range(n):
        y += (A[k] - x)
    if y >= s:
        print(x)
    else:
        a = s - y
        print(x - ceil(a / n))