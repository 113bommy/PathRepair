a,b,c,d=map(int,input().split())
x1=b-a
x2=c-d
if b==0 and a==0 and abs(c-d)<=1:
	if c<=d:
		print("YES")
		if d==1 and c==0:ans=[3]
		else:ans=[3,2]*c+[3]*(d-c)
		print(*ans)
	else:
		print("YES")
		if c==1 and d==0:ans=[2]
		else:ans=[2,3]*d+[2]*(c-d)
		print(*ans)
elif c==0 and d==0 and abs(a-b)<=1:
	if a<=b:
		print("YES")
		if b==1 and a==0:ans=[1]
		else:ans=[1,0]*a+[1]*(b-a)
		print(*ans)
	else:
		print("YES")
		if a==1 and b==0:ans=[0]
		else:ans=[0,1]*b+[0]*(a-b)
		print(*ans)
elif b<a or c<d:
	print("NO")
elif a==b and c==d:
	print("YES")
	ans=[0,1]*a+[2,3]*c
	print(*ans)

elif x1==x2:
	print("YES")
	ans=[1,0]*a+[1,2]*x1+[3,2]*d
	print(*ans)
elif x1==x2+1:
	print("YES")
	ans=[1]+[0,1]*a+[2,1]*x2+[2,3]*d
	print(*ans)
elif x1+1==x2:
	print("YES")
	ans=[0,1]*a+[2,1]*x1+[2,3]*d+[2]
	print(*ans)
else: print("NO")