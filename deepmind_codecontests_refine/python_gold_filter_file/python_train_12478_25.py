import sys

N = int(input())

a = input()
b = input()

for i in range(N):
	if a[i:N] == b[0:N-i]:
		print(N+i)
		sys.exit()
		
print(2 * N)