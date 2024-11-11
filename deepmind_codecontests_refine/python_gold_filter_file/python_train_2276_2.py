import bisect
n,a,b=map(int,input().split())
t=set([])
for i in range(n):
    t.add(int(input()))
t=list(t)
t.sort()
ai=bisect.bisect_left(t,a)
bi=bisect.bisect_left(t,b)
print(len(t)-(bi-ai))
