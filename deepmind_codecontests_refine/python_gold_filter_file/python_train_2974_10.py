n = int(input())
s = input()
i,a = 0, []

while i < n:
	if s[i:i+3]=="ogo":
		a.append(i)
		i+=3
	elif s[i:i+2]=="go" and s[i-1]=="o" and i!=0:
		i+=2
	else:
		a.append(s[i])
		i+=1

r = ""
for i in a:
	if type(i)==int:
		r+="***"
	else:
		r+=i
print(r)