a,b,c = list(map(int,input().split()))
if c:
	if (b - a) % c == 0 and (b - a) // c >= 0:
		print("YES")
	else:
		print("NO")
else:
	if a == b:
		print("YES")
	else:
		print("NO")