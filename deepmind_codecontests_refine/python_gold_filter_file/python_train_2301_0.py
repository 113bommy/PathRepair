n,k=[int(i)for i in input().split()]
a=[int(i)for i in input().split()]
b=[]
bb=[]#кол-во видов приборов
for i in range(1,101):
	b.append(a.count(i))
	if b[i-1]!=0:
		bb.append(i)
qq=(((max(b)-1)//k)+1)


flag=(k*len(bb)*qq)-n

print(flag)


