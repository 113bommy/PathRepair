
from sys import stdin

n = int(stdin.readline())
a = list(map(int,stdin.readline().split()))

ans = []

for i in range(n):
    X = a[i]
    now = []
    for j in range(i+1,n):
        if a[j] < X:
            now.append((a[j],j))
    now.sort()
    now.reverse()

    for aj,j in now:
        #a[i],a[j] = a[j],a[i]
        ans.append((i+1,j+1))

print (len(ans))
for i in ans:
    print (*i)
        
