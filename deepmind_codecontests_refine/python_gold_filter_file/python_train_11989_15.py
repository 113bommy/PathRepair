import math
def ncr(n,r):
	f = math.factorial
	return f(n) / f(r) / f(n-r)
N=int(input())
a=[]
arr=[]
for i in range(26):
	arr.append(0)
for i in range(N):
	temp=input()
	temp=temp[0]
	arr[ord(temp)-97]+=1
min=0
for i in range(26):
	if arr[i]==3:
		min+=1
	elif arr[i]>3:
		m=0
		if arr[i]%2==0:
			m=2*ncr(arr[i]/2,2)
		else:
			x=arr[i]//2
			y=(arr[i]+1)/2
			m=ncr(x,2)+ncr(y,2)
		min+=m
print(int(min))