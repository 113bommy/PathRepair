import bisect as bis
n,k=map(int, input().split())
a=[int(i) for i in input().split()]

a=sorted(a)
stt=-1
i=0
while i<n-1:
	if a[i]==a[i+1]:
		stt=0
		break
	i+=1
if stt==0:
	pass

else:
	b=[e&k for e in a]
	for i,e in enumerate(b):
		if e>a[i]:
			x=bis.bisect(a,e,i+1)
			if e==a[x-1]:
				stt=1
				#print("yes",e,x)
				break
		elif e<a[i] :
			x=bis.bisect(a,e,0,i)
			if e==a[x-1]:
				stt=1
				#print("ye",e,i)
				break
	#pri
	if stt==-1:
		b=sorted(b)
		i=0
		while i<n-1:
			if b[i]==b[i+1]:
				stt=2
				break
			i+=1

print(stt)
