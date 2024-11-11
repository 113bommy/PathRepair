N,A = int(input()), list(map(int, input().split()))
b,r = [0]*N,[]

for i,x in enumerate(reversed(A)):
	if not x == sum(b[N-i-1::N-i])%2:
		b[N-1-i] = 1

for i,x in enumerate(b):
	if x:
		r.append(i+1)

print(len(r))
print(' '.join(map(str, r)))