n=input()
i=0
j=0
while j<len(n):
	if n[j:j+3]=="144":
		j+=3
	elif n[j:j+2]=="14":
		j+=2
	elif n[j:j+1]=="1":
		j+=1
	else:
		i=5
		break
print(["YES","NO"][i==5])
