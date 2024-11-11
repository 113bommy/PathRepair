s=input()
n=len(s)
if s[0]=="0" or s[-1]=="1" or any(s[i]!=s[n-i-2] for i in range(n-1)):
	print(-1)
	exit()
ans=[]
now=0
for i,c in enumerate(s[:-1]):
	if c=="1":
		ans.append("{} {}".format(now+1,i+2))
		now=i+1
	else:
		ans.append("{} {}".format(now+1,i+2))
print(*ans,sep="\n")