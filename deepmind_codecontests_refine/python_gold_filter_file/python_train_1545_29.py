n=int(input())
sn=[input() for _ in range(n)]
m=int(input())
sm=[input() for _ in range(m)]
l=list(set(sn))
print(max(0,max([sn.count(l[i])-sm.count(l[i]) for i in range(len(l))])))