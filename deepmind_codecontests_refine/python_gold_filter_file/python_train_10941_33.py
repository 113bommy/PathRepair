n=int(input())
d={"A":10000000,"B":1000000000,"C":1000000000,"AB":1000000000,"BC":1000000000,"AC":10000000000,"ABC":10000000000}
for i in range(n):
	a1,a2=map(str,input().strip().split())
	l1=list(a2)
	l1.sort()
	a2="".join(l1)
	a1=int(a1)
	d[a2]=min(a1,d[a2])
o=min(d["A"]+d["B"]+d["C"],d["A"]+d["BC"],d["B"]+d["AC"],d["C"]+d["AB"],d["AB"]+d["BC"],d["AC"]+d["AB"],d["AC"]+d["BC"],d["ABC"])
if (o>300000):
	print (-1)
else:
	print (o)