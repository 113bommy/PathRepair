def rev(s):
	if s=="B":
		return "W"
	else:
		return "B"
n=int(input())
s=list(input())
ans=[]
if n%2==0:
	if s.count("B")%2==1:
		print (-1)
		exit()
if s.count("B")%2==0:
	i=0
	while i<n-1:
		if s[i]=="B":
			ans.append(i+1)
			s[i+1]=rev(s[i+1])
		i+=1
else:
	i=0
	while i<n-1:
		if s[i]=="W":
			ans.append(i+1)
			s[i+1]=rev(s[i+1])
		i+=1

print (len(ans))
if len(ans)!=0:
	print (*ans)

