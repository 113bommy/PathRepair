from collections import Counter
n,k = map(int,input().split())
arr = [int(i) for i in input().split()]
d = Counter(arr)
color = {}
ans = []
for i in range(k):
    color[i+1] = []
f = True if n >= k else False
for i in d:
    if d[i] > k:
        f = False
c = 1
if f:
    print('YES')
    for i in arr:
        if i not in color[c]:
            ans.append(c)
            color[c].append(i)
            c = c + 1 if c != k else 1
            
        else:
            while(i in color[c]):
               c = c +  1 if c != k else 1
            ans.append(c)
            color[c].append(i)
            c = c+ 1 if c != k else 1
    print(*ans)
else:
    print('NO')      
            