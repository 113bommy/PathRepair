n,x,y = map(int,input().split())
num = input().strip()
num = num[n-x:]
count=0
for z in range(len(num)):
	if(num[z]=='1'):
		count+=1
if(num[x-y-1]=='1'):
	count-=1
else:
	count+=1
print(count)