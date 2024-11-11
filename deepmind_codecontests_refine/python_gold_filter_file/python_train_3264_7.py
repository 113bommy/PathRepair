n,m=map(int,input().split())
c=list(map(int,input().split()))
inc=sorted(c)
dec=inc[::-1]
tot_max=0
w=[]
for i in range(len(inc)):
	for j in range(inc[i],0,-1):
		w.append(j)

w1=sorted(w)[::-1]


print(sum(w1[:n]), sum(w[:n]))


