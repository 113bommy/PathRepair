for _ in range(int(input())):
	n=int(input())
	l=list(map(int,input().split()))
	s=sum(l)
	t=l[0]
	for i in range(1,n):
		t=t^l[i]
	if 2*t==s:
		print("0")
		print()
	else:
		print(2)
		print(s+t,t)