n = int(input())
a = []
mn = 1e9
mx = -1e9
for i in range(n):
    l, r = map(int, input().split())
    a.append([l, r])
    mn = min(l, mn)
    mx = max(r, mx)
for i in range(n):
    if a[i][0] == mn and a[i][1] == mx:
        print(i + 1)
        exit(0)
print(-1)