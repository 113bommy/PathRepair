n,d=map(int,input().split())
mx=0
s="1"*n
k=0
for i in range(d):
	inp=input()
	if inp==s:
		k=0
	else:
		k+=1
	mx=max(mx,k)
print(mx)
