import sys
import math

def swap(x, y, a):
	temp = a[x]
	a[x] = a[y]
	a[y] = temp
	return a

def solve():
	return None

def main():
	q = []
	for line in sys.stdin.readlines():
		q.append(line)

	for i in range(len(q)):
		q[i] = q[i].rstrip().split(' ')
		q[i] = [int(x) for x in q[i]]

	for i in range(1, len(q),2):
		n = q[i][0]
		k = q[i][1]
		a = q[i+1]
		# print(n, k, a)
		u = len(set(a))
		if k == 1 and u!= 1:
			print(-1)
		elif k ==1 or u == 1:
			print(1)
		else:
			ret = math.ceil((u - k) / (k-1))
			# print("ret ", ret, u, k)
			print(ret + 1)
		# solve(q[i])

if __name__ == '__main__':
	main()