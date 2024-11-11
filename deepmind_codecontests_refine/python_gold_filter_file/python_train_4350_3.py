N=int(input())
ans=""

for _ in range(10**5):
	N-=1
	ans+=chr(ord("a")+(N%26))
	N=N//26
	if N<=0:
		break

print(ans[::-1])