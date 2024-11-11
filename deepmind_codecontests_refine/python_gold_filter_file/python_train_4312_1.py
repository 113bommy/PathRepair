n = int(input())
Min = -1e10
Max = 1e10
ans = "no"

def f(x, y):
	return x[0] < y[0] < x[1] < y[1] or \
	       y[0] < x[0] < y[1] < x[1]



xs = list(map(int, input().split()))

for i in range(1, len(xs) - 1):

	for j in range(0, i):
		if f([min(xs[i:i+2]), max(xs[i:i+2])], [min(xs[j:j+2]), max(xs[j:j+2])]):
			ans = "yes"
			break

print(ans)