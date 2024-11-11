x=int(input());a=list(map(int,input().split()));b={}
for i in range(x):
	tem=a[i]
	if tem-i in b.keys():
		b[tem-i]+=tem
	else:
		b[tem-i]=tem
print(max(b.values()))