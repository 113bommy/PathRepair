n,m = map(int,input().split(" "))
left, right = 1, n
for i in range(0,m):
	hint = input()
	number = int(hint[hint.index("of ") + 3:])
	if hint[7] == 'r':
		left = max(left,number + 1)
	else:
		right = min(right,number - 1)
if(right < left):
	print(-1)
else:
	print(max(min(n,right - left + 1), 1))