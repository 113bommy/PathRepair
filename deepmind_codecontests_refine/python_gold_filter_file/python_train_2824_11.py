j=input()
l=input().split()
start=0
ma=1
count=0
for i in range(len(l)):
	if int(l[i])==int(l[i-1]):
		if ma<count:
			ma=count
		count=1
	else:
		count+=1
print(max(ma,count))