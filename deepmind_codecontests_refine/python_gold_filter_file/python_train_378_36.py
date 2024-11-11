n = int(input())
arr = sorted([int(i) for i in input().split()])

a, b = 0, 0

for i in range(n//2):
	a += abs(arr[i] - 1 - i * 2);
	b += abs(arr[i] - 2 - i * 2);

print(min(a, b))
