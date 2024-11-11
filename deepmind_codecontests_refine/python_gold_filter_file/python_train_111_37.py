n = int(input())
a = [int(i) for i in input().split()]

s = sum(a)

for k in range(max(a),10000):
	if n*k-s>s:
		print(k)
		exit()
