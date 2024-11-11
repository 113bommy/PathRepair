n, m = map(int, input().split()); d1=[[] for t in range(n+m)]; d2=[[] for t in range(m+n)];
                                        
for t in range(n):
    a = list(map(int, input().split()))
    for i in range(m):
        d1[t+i].append(a[i]) 

for t in range(n):
    a = list(map(int, input().split()))
    for i in range(m):
        d2[t+i].append(a[i])
flag = True
for t in range(n+m-1):
    d1[t].sort()
    d2[t].sort()
    if d1[t]!=d2[t]:
        print("NO")
        flag = False
        break
if flag:
    print("YES")
