n, p, k = map(int, input().split())
if p-k > 1:
	print('<<', end = ' ')
for i in range(max(1, p-k), p):
	print(i, end = ' ')	
print('(', end = '')
print(p, end = '')
print(')', end = ' ')
for i in range(p+1, min(n, p+k)+1):
	print(i, end = ' ')
if p+k < n:
	print('>>', end = ' ')	