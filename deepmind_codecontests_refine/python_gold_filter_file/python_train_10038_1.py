g=input()
n,m=[int(x) for x in g.split()]
liM=[]
liN=[]
for i in range(10**6+1):
	liM.append(0)
t=input()
for x1 in t.split():
	liN.append(int(x1))
w=input()
for x2 in w.split():
	liM[int(x2)]+=1
	end1=int(x2)	
result=0
coun=[]
sumA=sum(liM[:end1+1])
for ki in range(1,liN[n-1]+1):
	coun.append(sumA-liM[ki-1])
	sumA=sumA-liM[ki-1]
result=0
counter=0
#print(len(coun),liN[n-1])
for i in range(n):
	gh=min(1,coun[liN[n-i-1]-1]-counter)
	#if gh==coun[end-i-1]-counter:
		#result+=liN[end-i-1]-coun[end-i-1]-counter
	counter+=gh 
print(n-counter)
