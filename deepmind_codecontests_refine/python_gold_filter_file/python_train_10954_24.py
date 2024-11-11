n = int(input())
arr = [int(j) for j in input().split()]
for i in range(1, n+1):
	arr[i-1] = [arr[i-1], arr[i-1]-i]

freq = [0]*1000000
for i in range(n):
	# print(arr[i][0], arr[i][1])
	freq[arr[i][1]] += arr[i][0]

print(max(freq))