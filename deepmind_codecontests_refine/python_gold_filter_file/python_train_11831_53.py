n = list(input())
c1=0
for i in range(len(n)):
	if n[i].isdigit()==False and n[i]=='a'or n[i]=='e'or n[i]=='i' or n[i]=='o' or n[i]=='u':
		c1+=1
	else:
		if n[i].isdigit() and int(n[i])%2==1 :
			c1+=1
print(c1)