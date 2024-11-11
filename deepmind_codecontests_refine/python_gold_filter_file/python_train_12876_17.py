n=int(input())
l=list(input().split())
d={}
c=0
for i in l:
	d[i]=d.get(i,0)+1
a=d.keys()
for i in a:
	if i!="0":
		c+=1
print(c)

