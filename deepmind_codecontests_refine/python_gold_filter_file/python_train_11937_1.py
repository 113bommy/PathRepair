n = int(input())
block = []

def flip(ch):
	return "1" if ch == "0" else "0"

for i in range(4):
	if i:
		input()
	left = "1"
	c0 = c1 = 0	
	for j in range(n):
		s = input()
		expect = left
		for c in s:
			if c == expect:
				c0 += 1
			else:
				c1 += 1
			expect = flip(expect)
		left = flip(left)
	block.append( [c0, c1] )		
	
ans = 4 * n * n
import itertools
for a, b, c, d in itertools.permutations(range(4), 4):
	v = block[a][0] + block[b][0] + block[c][1] + block[d][1]
	ans = min(ans, v)
print(ans)