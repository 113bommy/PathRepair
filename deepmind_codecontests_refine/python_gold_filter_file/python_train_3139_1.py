H, n = list(map(int,input().split()))
hp = list(map(int,input().split()))
sum = H
mini = H
import sys
for i in range(n):
	sum = sum + hp[i]
	mini = min(mini, sum)
	if sum <= 0:
		print(i+1)
		sys.exit(0)
if sum>=H:
	print(-1)
	sys.exit(0)
x =1 + (mini-1) // (H-sum)

H = H - (H-sum)*x
wyn = n*x
for i in hp:
	wyn += 1
	H = H + i
	if H<=0:
		print(wyn)
		break
	