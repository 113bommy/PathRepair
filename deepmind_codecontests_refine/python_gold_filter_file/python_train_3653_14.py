a,b,c=map(int,input().split())
ans=''
if a == max(a,b):
	for i in range(c+1):
		if(i%2!=0):
			ans=ans+"1"
			b-=1
		elif(i%2==0):
			ans = ans+"0"
			a-=1

else:
	for i in range(c+1):
		if(i%2!=0):
			ans=ans+"0"
			a-=1
		elif(i%2==0):
			ans = ans+"1"
			b-=1

o=''
z=''
for j in range(b):
	o = o+"1"
for j in range(a):
	z = z+"0"

if ans[0]=="0":
	ans= z+"0"+o+ans[1:]
else:
	ans = o+"1"+z+ans[1:]

print(ans)