n = int(input())
l = list(map(int,input().split()))
q = []
w = []
r = [0]
for i in range(n):
    q.append([l[i],i+1])
q=sorted(q)
for j in range(1,n):
    if q[j][0]==q[j-1][0]:
        r[0]+=1
        r.append(j+1)
    if r[0]==2:
        break
for i in q:
    w.append(i[1])
if r[0]==2:
    print("YES")
    print(*w)
    for k in range(1,3):
        w[r[k]-1],w[r[k]-2]=w[r[k]-2],w[r[k]-1]
        print(*w)
else:
    print("NO")