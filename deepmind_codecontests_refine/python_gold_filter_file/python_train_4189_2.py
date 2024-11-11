from sys import stdin, stdout
from collections import deque, Counter
from copy import copy
rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()

def main():
	T = int(rl())
	for _ in range(T):
		line = rll()
		n, s = int(line[0]), line[1]
		cnts = Counter(s)
		D, I = cnts[">"], cnts["<"]
		Darr = deque(i for i in range(D, 0, -1))
		Iarr = deque(i for i in range(D+1, n+1))
		# Darr2, Iarr2 = Darr.copy(), Iarr.copy()
		nums = deque(i for i in range(1,n+1))
		#Shortest LIS
		runs, L = [], 0
		for R in range(len(s)+1):
			if R == len(s) or s[R] != s[L]:
				runs.append((R - L, s[L]))
				L = R
		short = [Iarr.popleft()]
		long_ = []
		# print(runs)
		# print(Darr)
		# print(Iarr)
		# print(Darr)
		# print(Iarr)
		for rlen, rtype in runs:
			local = []
			if rtype == "<":
				for _ in range(rlen):
					local.append(Iarr.pop())
				short.extend(local[::-1])
			else:
				for _ in range(rlen):
					local.append(Darr.popleft())
				short.extend(local)

		for rlen, rtype in runs:
			local = []
			if rtype == "<":
				for _ in range(rlen):
					local.append(nums.popleft())
				long_.extend(local)
			else:
				for _ in range(rlen):
					local.append(nums.pop())
				long_.extend(local)
		long_.append(nums.pop())
		ans_short = " ".join((str(x) for x in short))
		ans_long = " ".join((str(x) for x in long_))
		stdout.write(str(ans_short));stdout.write("\n")
		stdout.write(str(ans_long));stdout.write("\n")
	stdout.close()

if __name__ == "__main__":
	main()