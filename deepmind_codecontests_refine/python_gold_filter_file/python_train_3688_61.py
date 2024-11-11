n = int(input())

aa = list(map(int, input().split()))
a, b = map(int, input().split())
x = b-a
ans = 0
for i in range(a-1,b-1):
	ans += aa[i]
print (ans)