n,k = [int(x) for x in input().split()]
S = list(input())

if len(S)==1:
	if k==0: print(''.join(S))
	else: print(0)
	quit()

if S[0]!='1' and k!=0:
	S[0] = '1'
	k -= 1

ptr = 1
while ptr<n and k>0:
	if S[ptr]!='0':
		S[ptr] = '0'
		k -= 1
	ptr += 1

print(''.join(S))