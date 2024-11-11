"""for p in range(int(input())):

	n,k=map(int,input().split(" "))
	number=input().split(" ")
	chances=[k for i in range(n)]

	prev=-1
	prev_updated=-1
	last_used=False
	toSub=0
	start=0

	prevSub=0

	if(number[0]=='1'):
		prev=0
		prev_updated=0
		start=1

	for i in range(start,n):
		
		if(number[i]=='1'):
		#	print("\ni",i,"\ntoSub",toSub,"\nprevUpadted",prev_updated,"\nprev",prev,"\nlast_used",last_used)
			f1=False
#			toSub+=1
			toSub=0

			zeros=i - prev_updated - 1

			if(last_used):
				zeros-=1

			#chances[i]-=toSub

			#print(prevSub,(i - prev - 1 ) +1)
			if(i - prev - 1 <= prevSub):
				chances[i]-= prevSub - (i - prev - 1 ) +1
				if(chances[i]<zeros):
					chances[i]=zeros
				toSub+= prevSub - (i - prev - 1 ) +1
				f1=True

			if(zeros==0 or chances[i]==0):
				prev_updated=i
				prev=i
				last_used=False
				prevSub=toSub
				continue
		#	print("\nchances:  ",chances[i],"\t\tzeroes :   ",zeros,"\t\tprevSub :",prevSub)

			if(chances[i]>zeros):
		#		print("\t\t\t\t1")
				number[i-zeros]='1'
				number[i]='0'
				prev_updated=i-zeros
				last_used=False
			elif(chances[i]==zeros):
		#		print("\t\t\t\t2")
				number[i]='0'
				number[i-chances[i]]='1'
				prev_updated=i-chances[i]
				last_used=True
			else:
		#		print("\t\t\t\t3")
				number[i]='0'
				number[i-chances[i]]='1'
				prev_updated=i-chances[i]
				last_used=True
			prev=i

			prevSub=toSub

			if(prev_updated>2 and f1):
				if(number[prev_updated]=='1' and number[prev_updated-1]=='0' and number[prev_updated-2]=='1'):
					last_used=False
				#if()

		#	print("\ni",i,"\ntoSub",toSub,"\nprevUpadted",prev_updated,"\nprev",prev,"\nlast_used",last_used)
		#	print(number)
		else:
			toSub=0

	print(*number)
#	print(chances)"""

"""class offer:
	def __init__(self, n, fre):
		self.num = n
		self.free = fre
		self.delta= n-fre
		

n,m,k=map(int,input().split(" "))

shovel=list(map(int,input().split(" ")))

#dicti={}

offers=[]
temp_arr=[False for i in range(n)]

for i in range(m):
	p,q=map(int,input().split(" "))
	if(p>k):
		continue
	offers.append(offer(p,q))
#	dicti[p]=q

#for i in dicti:
#	dicti[i].sort()	

shovel.sort()
shovel=shovel[:k+1]

offers.sort(key=lambda x: x.delta/x.num,reverse=True)

bestoffer=[]

for i in offers:
	if(not temp_arr[i.num]):
		temp_arr[i.num]=True
		bestoffer.append(i)

cost=0

for i in bestoffer:
	
	
for p in range(int(input())):
	arr=list(input())

	n=len(arr)
	for i in range(n):
		arr[i]=ord(arr[i])-96

	arr.sort()

	arr1=arr[:n//2]
	arr2=arr[n//2:]
	arr=[]
	#print(arr,arr1,arr2)
	i1=n//2-1
	i2=n-i1-2

	while (i1!=-1 and i2!=-1):
		arr.append(arr1[i1])
		arr.append(arr2[i2])
		i1-=1
		i2-=1
	if(i1!=-1):
		arr.append(arr1[i1])
	elif(i2!=-1):
		arr.append(arr2[i2])

	#print(arr)

	s=""
	for i in range(n-1):
		if(abs(arr[i]-arr[i+1])==1):
			s=-1
			print("No answer")
			break
		else:
			s+=chr(arr[i]+96)

	if(s!=-1):
		s+=chr(arr[-1]+96)
		print(s)"""

"""
n,m=map(int,input().split(" "))

seti=[]
ans=[1 for i in range(n)]


for i in range(m):
	arr=list(map(int,input().split(" ")))
	
	if(arr[0]>1):
		seti.append(set(arr[1:]))
	else:
		m-=1

parent=[-1 for i in range(m)]
#print(seti)
for i in range(m-1):
	for j in range(i+1,m):
		if(parent[j]==-1):
			if(len(seti[i].intersection(seti[j]))>0):
				seti[i]=seti[i].union(seti[j])
				parent[j]=i

#print(parent)

for i in range(m):
	if(parent[i]==-1):
		temp=list(seti[i])
		store=len(temp)
		for j in temp:
			ans[j-1]=store

print(*ans)


for p in range(int(input())):
	arr=list(input())

	n=len(arr)
	for i in range(n):
		arr[i]=ord(arr[i])-96

	arr.sort()

	arr1=arr[:n//2]
	arr2=arr[n//2:]
	arr=[]
	#print(arr,arr1,arr2)
	i1=n//2-1
	i2=n-i1-2

	while (i1!=-1 and i2!=-1):
		arr.append(arr1[i1])
		arr.append(arr2[i2])
		i1-=1
		i2-=1
	if(i1!=-1):
		arr.append(arr1[i1])
	elif(i2!=-1):
		arr.append(arr2[i2])

	s=""
	for i in range(n-1):
		if(abs(arr[i]-arr[i+1])==1):
			s=-1
			print("No answer")
			break
		else:
			s+=chr(arr[i]+96)

	if(s!=-1):
		s+=chr(arr[-1]+96)
		print(s)"""
#n=0

n=int(input())
arr=list(map(int,input().split(" ")))
record=arr[-1]
arr.reverse()
if(record==0):
	print(n-arr.index(1))
else:
	print(n-arr.index(0))