n = int(input())
a = list(map(int, input().split()))
a = [abs(a[i] - a[i + 1]) for i in range(n - 1)]
 
ans = t1 = t2 = 0
 
for i in a:
	t1, t2 = max(t2 + i, 0), max(t1 - i, 0)
	ans = max(ans,t1,t2)
print(ans)