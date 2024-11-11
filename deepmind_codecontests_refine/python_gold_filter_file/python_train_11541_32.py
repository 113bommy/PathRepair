a,b,c=map(int, input().split())
ans= "NO"
for i in range(100):
	if a*i % b == c:
		ans ="YES"
print(ans)