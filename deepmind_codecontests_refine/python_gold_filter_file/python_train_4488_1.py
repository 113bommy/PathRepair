a,b=map(int,input().split())
s=str(input())
l=list(s)
e="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
k=set(l)
if len(k)<b:
	print("0")
else:
	r=[]
	for i in range(b):
		f=l.count(e[i])
		r.append(f)
	print(b*min(r))