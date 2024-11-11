n, m = map(int, input().split())
sdst = 0
for i in range(n):
    sdst += abs(i - n//2)
bdst = 0
for i in range(n):
    bdst += abs(i)
ans = 0
for i in range(m):
    x,d = map(int, input().split())
    if d < 0:
        s = x*n + sdst*d
    else:
        s = x*n + bdst*d
    ans += s
ans /=n
print("%.8f" % ans)