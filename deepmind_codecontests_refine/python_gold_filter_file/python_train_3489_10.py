n,l,d = int(input()),[],{}
for i in range(n):
    tt = tuple(map(int,input().split()))
    d[tt] = i+1
    l.append(tt)
t1 = l[0]
l = sorted(l,key= lambda x:(x[0]-t1[0])**2 + (x[1]-t1[1])**2)
t2 = l[1]
for i in range(2,n):
    t3 = l[i]
    if (t2[1] - t1[1])*(t3[0] - t1[0]) != (t3[1] - t1[1])*(t2[0] - t1[0]): break
print(d[t1],d[t2],d[t3])
