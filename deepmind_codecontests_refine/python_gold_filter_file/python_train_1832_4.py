import sys

inp = sys.stdin.readline()
inp_ = [inp[i] for i in range(len(inp)-1)]

def f(x):
	S = 0
	for i in range(0, int(0.5 *len(x))):
		if x[i] != x[len(x)-i-1]:
			S += 1
	return S

if (((f(inp_) == 0 and len(inp_) % 2 == 1)) or f(inp_) == 1):
	print("YES")
	
	
else:
	print("NO")
	
