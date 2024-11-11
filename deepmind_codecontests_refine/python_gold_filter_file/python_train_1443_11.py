N = int(input())
A = sorted(map(int,input().split()))
B = []

if N%2:
	B = [0]
	for i in range(N//2):
		B += [(i + 1)*2]*2
else:
	for i in range(N//2):
		B += [i*2 + 1]*2	
#print(A, B)
#print(B)
if A==B:
	print(2**(N//2)%((10**9) + 7))
else:
	print(0)


