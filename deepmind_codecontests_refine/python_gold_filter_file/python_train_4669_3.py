N = int(input())

maxi = -1
sc = 0

for i in range(N):
	A, B = map(int, input().split())
	if A > maxi:
		maxi = A
		sc = B
print(maxi + sc)