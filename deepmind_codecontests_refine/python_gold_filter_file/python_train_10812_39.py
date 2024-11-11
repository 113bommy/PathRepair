s=input()
k=int(input())
ss=[]
for i in range(len(s)):
	ss.append(ord(s[i])-ord("a"))
i=0
while k>0:
	if i==len(s)-1:
		ss[i]=(k+ss[i])%26
		break
	elif k>=26-ss[i] and ss[i]!=0:
		k-=(26-ss[i])
		ss[i]=0
	i+=1
ans=""
for i in range(len(s)):
	ans+=chr(ord("a")+ss[i])
print(ans)
