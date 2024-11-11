from bisect import bisect_left as bs
if __name__ == "__main__":
	n, k = [int(_) for _ in input().strip().split()]
	arr = [int(_) for _ in input().strip().split()]
	arr.sort()
	l = []
	for i in range(n):
		if len(l) == 0:
			l.append(arr[i])
		else:
			while len(l) > 0 and l[-1] + k >= arr[i] and l[-1] < arr[i]:
				l.pop()
			l.append(arr[i])
	print(len(l))
