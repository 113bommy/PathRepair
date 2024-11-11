n = int(input())
x = list(map(int,input().split()))
y = sorted(x)
l = y[n//2-1]
r = y[n//2]
for i in range(n):
    if x[i] <= l:print(r)
    else:print(l)
