store=""
j=0
n,k=map(int,input().split())
for i in range(97,97+n):
	if len(store)<k:
		store+=chr(i)
	else:
		store+=store[j]
		j+=1
print(store)
		
