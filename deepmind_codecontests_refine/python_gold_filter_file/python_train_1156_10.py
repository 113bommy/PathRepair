n = int(input())
n1 = n
ans = 1
maxcnt = 0
flag = 0
for i in range(2,n1 + 1):
	if i > n:
		break
	if n % i == 0:
		ans *= i
		cnt = 0
		while n % i == 0:
			n /= i
			cnt += 1
		if cnt != maxcnt and maxcnt > 0:
			flag = 1
		if cnt > maxcnt:
			maxcnt = cnt

myb = [1, 2, 4, 8, 16, 32]

if maxcnt > 0:
	if maxcnt not in myb:
		flag = 1

for i in range(len(myb)):
	if myb[i] >= maxcnt:
		anscnt = i
		break
	

print(ans, anscnt + flag)
	