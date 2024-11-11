

t=input()
t=list(t)
# print(t)
t.sort()
# print(t)
a=t[-1]
# print(a)
co=1
for i in range (len(t)-2,-1,-1):
	if t[i]==a:
		co+=1
	else:
		break
for i in range (co):
	print(a,end="")