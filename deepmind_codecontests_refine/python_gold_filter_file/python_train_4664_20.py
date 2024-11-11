x, y = map(int, input().split())
ans = 0
ans += max(0, (4-x)*100000)
ans += max(0, (4-y)*100000)
if x == 1 and y == 1:
	ans += 400000
print(ans)