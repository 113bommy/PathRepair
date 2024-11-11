n = int(input())
Min = -1e10
Max = 1e10
ans = "no"

def f(x, y):
	return x[0] < y[0] and x[1] > y[0] and x[1] < y[1] or \
	       x[0] > y[0] and x[0] < y[1] and x[1] > y[1] 



xs = list(map(int, input().split()))

align = [0, 0]*len(xs)

align[0] = xs[0]
align[1] = xs[0]

for i in range(1, len(xs)):
	#print(align)
	for j in range(0, i):
		if f([min(xs[i-1:i+1]), max(xs[i-1:i+1])], align[2*j:2*j+2]):
			ans = "yes"
			break
	if xs[i] >= xs[i-1]:
		align[2*i-1] = xs[i]
		align[2*i] = xs[i-1]
		align[2*i+1] = xs[i]
	else:
		align[2*i-2] = xs[i]
		align[2*i] = xs[i]
		align[2*i+1] = xs[i-1]

print(ans)