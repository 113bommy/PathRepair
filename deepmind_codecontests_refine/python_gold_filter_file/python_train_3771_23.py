n=int(input())
s=input()
b,w=[s[0]],[]
ans="YES"
for i in range(1,n):
	if s[i]>=b[-1]:
		b.append(s[i])
	elif len(w)==0 or s[i]>=w[-1]:
		w.append(s[i])
	else:
		ans="NO"
		break
if ans=="YES":
	print (ans)
	j,k=0,0
	for i in range(n):
		if j<len(b) and s[i]==b[j]:
			print ("0",end="")
			j+=1
		else:
			print ("1",end="")
			k+=1
	print ()
else:
	print (ans)