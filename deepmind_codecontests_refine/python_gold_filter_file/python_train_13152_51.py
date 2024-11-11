n,a,b,c = [int(i) for i in input().split()]
line=[a,b,c]

a,b,c = list(sorted(line))
pieces = (n+1)*[-4000]     #！！！！这里为了避免5=2*2的情况，必须把初值设得非常小！！！
pieces[0] = 0

for i in range(1,n+1):
	if i>=a:
		pieces[i] = pieces[i-a] + 1
	if i>=b and pieces[i-b]+1>pieces[i]:
		pieces[i] = pieces[i-b] + 1
	if i>=c and pieces[i-c]+1>pieces[i]:
		pieces[i] = pieces[i-c] + 1

print(pieces[n])