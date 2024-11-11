n,m  =  map(int,input().split())
a=sorted(list(map(int,input().split())))
a.append(10000000000)
n=100000
z=list(range(1,200001))
z=list(set(z)-set(a))
p=[]
ans=0
for i in z :
	if i>m :
		break
	else:
		ans+=1
		p.append(i)
		m-=i
print(ans)
print(*p)