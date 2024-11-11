n,c=map(int,input().split())
d=list(map(int,input().split()))

if d.index(min(d)) == 0:
	print('0')
else:
	w=[]
	for i in range(len(d)-1):
		w.append(d[i]-d[i+1])
	print(max(0,max(w)-c))
