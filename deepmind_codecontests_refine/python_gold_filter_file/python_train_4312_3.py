n=int(input())
l=list(map(int,input().split()))
maxx=l[0]
minn=l[0]

for i in range(0,n-1):
	
	if l[i+1]>l[i]:
		if l[i]>minn and l[i]<maxx and l[i+1]>maxx:
			print("yes")
			exit()
		elif l[i]<minn and l[i+1]>minn and l[i+1]<maxx :
			print("yes")
			exit()

		else:
			if l[i]>maxx:
				maxx=l[i]
			if l[i]<minn:
				minn=l[i]
	elif l[i+1]<l[i]:
		if l[i+1]>minn and l[i+1]<maxx and l[i]>maxx:
			print("yes")
			exit()
		elif l[i+1]<minn and l[i]>minn and l[i]<maxx:
			
			print("yes")
			exit()
		else:
			if l[i]>maxx:
				maxx=l[i]
			if l[i]<minn:
				minn=l[i]
print("no")
