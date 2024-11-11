n=int(input())
for i in range(n):
	p,k=map(int,input().split())
	r=(k+1-p)
	s=k-p
	if p%2==1 and r%2==1 and s!=0:
		print((r//2)-k)
	elif s==0 and p%2==1:
		print(-p)
	elif s==0 and p%2==0:
		print(p)
	elif p%2==1 and r%2==0 and s!=0:
		print(r//2)
	elif p%2==0 and r%2==0:
		print(-r//2)
	elif p%2==0 and r%2==1:
		print(-(r//2)+k)