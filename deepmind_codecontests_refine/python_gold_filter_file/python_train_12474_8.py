s=input()
n=int(input())
a=[]
for i in range(0,len(s),n):
	a.append(s[i])
print(*a,sep="")
