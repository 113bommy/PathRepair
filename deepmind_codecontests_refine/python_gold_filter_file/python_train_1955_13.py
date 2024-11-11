N=int(input())
A=[]
PRECISION_DIGITS=9
cnt={}


for n in range(N):
	tmpA = float(input())
	tmpA = round(tmpA*10**PRECISION_DIGITS)
	#print(tmpA)

	five = 0
	two = 0
	while (tmpA % 2) == 0:
		two += 1
		tmpA //= 2
	while (tmpA % 5) == 0:
		five += 1
		tmpA //= 5

	# (10**9) -> (two,five)=(9,9)
	two -= PRECISION_DIGITS
	five -= PRECISION_DIGITS

	if (two,five) in cnt:
		cnt[(two,five)]+=1
	else:
		cnt[(two,five)]=1

# print(cnt)
ans = 0
for t1, cnt1 in cnt.items():
	for t2, cnt2 in cnt.items():
		# 2**a(a>=0) and 5**b(b>=0) => integer
		if 0 <= t1[0]+t2[0] and 0 <= t1[1]+t2[1]:
			if t1 < t2:
				ans += int(cnt1*cnt2)
			elif t1 == t2:
				# same entry
				# Total number of combinations choose 2 items
				# nC2 = n*(n-1)/2
				ans += int((cnt1*(cnt2-1))/2)


print(ans)

