n=int(input())
a=input()
b=input()
d={"ab":0,"ba":0}
ca=0
cb=0
for i in range(n):
	if a[i]=="a":
		ca+=1
	else:
		cb+=1
	if b[i]=="a":
		ca+=1
	else:
		cb+=1
if ca%2==1 or cb%2==1:
	print (-1)
else:
	for i in range(n):
		if a[i]!=b[i]:
			d[a[i]+b[i]]+=1
	print (d["ab"]//2+d["ba"]//2+d["ab"]%2+d["ba"]%2)
	cross=False
	if d["ab"]!=0:
		prev=False
		for i in range(n):
			if a[i]+b[i]=="ab":
				if not prev:
					prev=True
					pi=i
				else:
					print (pi+1,i+1)
					prev=False
		if prev:
			cross=pi+1
	if d["ba"]!=0:
		prev=False
		for i in range(n):
			if a[i]+b[i]=="ba":
				if not prev:
					prev=True
					pi=i
				else:
					print (pi+1,i+1)
					prev=False
		if cross:
			print (cross,cross)
			print (cross,pi+1)
