
n = int(input())
a = input()
a = list(a)


t=0

g =a.count("?")


if g==0:
	print("No")
	exit()

for i in range(n-1):
	j = i+1
	if (a[i]==a[j] and a[i]!="?") :
		print("No")
		exit()
for i in range(1,n-1):
	if a[i-1]!=a[i+1] and a[i]=="?" and (a[i-1]!="?" and a[i+1]!="?" ):
		t+=1
		
if t>=g and t!=0:
	print("no")
	exit()
print("Yes")
		