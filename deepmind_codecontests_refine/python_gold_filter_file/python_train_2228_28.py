n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
diff = arr[n-1]-arr[0]
for i in range(m-n+1):
	curr = arr[i+n-1]-arr[i]
	if(curr < diff):
		diff = curr
print(diff)