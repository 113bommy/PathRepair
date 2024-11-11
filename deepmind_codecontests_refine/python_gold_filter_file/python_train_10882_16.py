# t=int(input())

# while(t>0):
n,m=[int(x)for x in input().split()]
b=[int(x)for x in input().split()]
sn=set(b)
summ=0
count=0
a=[]
i=1
while(i>0):
	# print("hi",i)
	if summ+i<=m and i not in sn:
		summ+=i
		count+=1
		a.append(i)
	
	if summ==m or summ+i>m:
		break
	# else:
	# 	break
	i+=1

print(count)
for i in range(count):
	print(a[i],end=' ')



	# t-=1


