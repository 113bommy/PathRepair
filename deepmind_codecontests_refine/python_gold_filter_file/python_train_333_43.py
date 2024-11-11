# from math import ceil, log

b = {}
n, k = map(int, input().split())
a = list(map(int, input().split()))
b[0] = []
for x in a:
    j = 0
    while(x > 0):
        if(x in b):
            b[x].append(j)
        else:
            b[x] = [j]
        x //= 2
        j += 1
    b[0].append(j)

ans = 10**6

for i in b:
    b[i].sort()
    if(len(b[i]) >= k):
        ans = min(sum(b[i][:k]), ans)
    
print(ans)
