kk=lambda:map(int,input().split())
(n,c),a,b=kk(),kk(),kk()
l,s=c,0
print(0,end=' ')
for i in range(n-1):
	s,l=min(s,l)+next(a),min(s+c,l)+next(b)
	print(min(s,l),end=' ')