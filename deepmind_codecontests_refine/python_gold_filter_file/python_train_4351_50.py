A = [list(map(int, input().split())) for _ in range(3)]
N = int(input())
b = [int(input()) for _ in range(N)]

f=0
for v in b:
	for i in range(9):
		if A[i // 3][i % 3] == v:
			f|=1<<i
ans = 0
for v in [7,56,73,84,146,273,292,448]:
  ans |= f&v==v;
print('Yes' if ans else 'No')
