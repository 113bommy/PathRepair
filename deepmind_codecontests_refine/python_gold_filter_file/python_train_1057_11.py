x,y,z = map(int,input().split())
ans1 = (x+y)//z
p = x%z
q = y%z
if (p+q) >= z:
	ans2 = min(z-p,z-q)
else:
	ans2 = 0
print(ans1,ans2)