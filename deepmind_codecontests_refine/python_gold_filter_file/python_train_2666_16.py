n=int(input())
a=input().split()
ans=[]
for i in a:
	c=0
	for j in range(len(i)):
		if(ord(i[j])>=65 and ord(i[j])<=ord('Z')):
			c+=1
	ans.append(c)
print(max(ans))