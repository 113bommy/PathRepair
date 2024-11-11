ss = 0
n, s = map(int, input().split())
v = list(map(int, input().split()))

m,ss = min(v), sum(v)

if ss < s:
    print(-1)
else:
    print(min(m, (ss-s)//n))