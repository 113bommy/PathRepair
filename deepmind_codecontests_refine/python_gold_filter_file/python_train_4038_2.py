N, M, X= map(int, input().split())
arr=[list(map(int, input().split())) for _ in range(N)]

ans=float('inf')
for paint_h in range(2**N):
	temp_arr=[0]*(M+1)
	for i in range(N):
		if (paint_h>>i)&1==1:
			temp_arr=[a+b for (a, b) in zip(temp_arr, arr[i])]
	if all(i>=X for i in temp_arr[1:]):
		ans=min(ans, temp_arr[0])
print(ans if ans != float('inf') else -1)