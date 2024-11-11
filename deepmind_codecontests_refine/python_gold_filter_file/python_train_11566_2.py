# import sys 
# sys.stdin=open("input.in","r")
# sys.stdout=open("ot.out","w")


n=int(input())
s=input().split()
l=[]
for i in s:
	l.append(int(i))
# print(l)
count=l.count(1)
print(count)
for i in range(len(l)):
	if i==len(l)-1:
		print(l[i])
	


	else:
		if l[i+1]==1:
			print(l[i],end=" ")