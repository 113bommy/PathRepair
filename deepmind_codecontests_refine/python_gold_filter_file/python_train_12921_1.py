n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
p = [0] * (n + 1)
mx = 0
for i in range(n):
    p[a[i]] = i + 1
for i in range(n):
    print(max(0, p[b[i]] - mx), end = ' ')
    mx = max(mx, p[b[i]])
