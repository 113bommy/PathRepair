s=list(input())
p=list("hello")
j=0
for i in s:
	if i==p[j]:
		j+=1
	if j==5:
		print("YES")
		exit()
print("NO")			