h, w = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
c = []
for i in range(n):
    c += [i+1]*a[i]
ans = []
for h_ in range(h):
    a = c[h_*w: w+h_*w]
    if h_ % 2 == 0:
        ans.append(a)
    else:
        ans.append(a[::-1])
for i in ans:
    print(*i)