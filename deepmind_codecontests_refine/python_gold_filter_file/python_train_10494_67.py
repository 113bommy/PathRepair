N, A, B, C, D = map(int, input().split())
S = input()

if "##" in S[A - 1:max([C, D])]:
	print("No")
	exit()

if D < C:
	if not "..." in S[B - 1 - 1:D + 1]:
		print("No")
		exit()

print("Yes")