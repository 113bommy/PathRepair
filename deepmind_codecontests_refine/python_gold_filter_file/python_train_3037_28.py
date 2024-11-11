n = int(input().strip())
arr = list(map(int, input().strip().split()))
pref_sum = [0]*n
pref_sum[0] = arr[0]
for i in range(1, n):
	pref_sum[i] = arr[i]+pref_sum[i-1]
pref_sum.insert(0, 0)
for _ in range(int(input())):
	l, r = map(int, input().split())
	print((pref_sum[r]-pref_sum[l-1])//10)