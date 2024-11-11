l=[]
for i in range(int(input())):
	a,b,c,d=(map(int,input().split()))
	l.append(a+b+c+d)
# print(l)
	

id=l[0]
# print(id)
# a=set(l)
# b=list(a)
l.sort(reverse=True)
# print(b)
for i in range(len(l)):
	if id==l[i]:
		print(i+1)
		break