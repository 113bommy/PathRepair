n=int(input())
l=list()
dot=0
let=0
for i in range(0,1002):
	if i%2==0:
		l.append('C')
	else:
		l.append('.')
if n%2==0:
	dot=int(n/2)
	let=int(n/2)
else:
	let=int(n/2)+1
	dot=int(n/2)
print((dot*dot)+(let*let))
for i in range(0,n):
	if i%2==0:
		print("".join(l[0:n]))
	else:
		print("".join(l[1:n+1]))