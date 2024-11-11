s=str(input())
count1=0
count2=0
for i in range(len(s)):
	if(s[i]=="-"):
		count1+=1
	elif(s[i]=="o"):
		count2+=1
if(count2==0):
	print("YES")
elif(count1%count2==0):
	print("YES")
else:
	print("NO")