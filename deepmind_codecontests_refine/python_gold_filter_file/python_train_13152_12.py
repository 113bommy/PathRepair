n, a, b, c = [int(i) for i in input().split()]
ans = [0] + [-10000]*8000
for i in range(n+1):
	ans[i] = max(max(ans[i-a], ans[i-b], ans[i-c])+1, ans[i])
print(ans[n])