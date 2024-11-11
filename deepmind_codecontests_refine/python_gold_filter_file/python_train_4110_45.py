
def point(p,t):
	return max(3*p/10,p-p/250*t)
a,b,c,d = map(int,input().split())
mi = point(a,c)
va = point(b,d)
if mi > va:
	print("Misha")
elif va > mi:
	print("Vasya")
else:
	print("Tie")