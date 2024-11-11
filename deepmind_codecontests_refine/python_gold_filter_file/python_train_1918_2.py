inf = 1000 * 1000 * 1000
def calc(x, y):
	if(x % a != 0 or y % b != 0):
		return inf
	s = x / a + y / b
	if(s % 2 == 1):
		return inf
	return max(x / a, y / b)
n, m, x, y, a, b = map(int, input().split())
if(x == 1 and y == 1 or x == 1 and y == m or x == n and y == 1 or x == n and y == m):
	print(0)
	exit(0)
if(x - a <= 0 and x + a > n or y + b > m and y - b <= 0):
	print('Poor Inna and pony!')
	exit(0)	
ans = calc(x-1, y-1)
ans = min(ans, calc(x-1, m-y))
ans = min(ans, calc(n-x, y-1))
ans = min(ans, calc(n-x, m-y))
ans = int(ans)
print(ans if ans != inf else 'Poor Inna and pony!')