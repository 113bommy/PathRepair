#import sys
#sys.stdin = open('input.txt', 'r')
s = input()
B, S, C = 0, 0, 0
for i in s:
	if i == 'B':
		B += 1
	if i == 'S':
		S += 1
	if i == 'C':
		C += 1
a, b, c = list(map(int, input().split()))
pa, pb, pc = list(map(int, input().split()))
money = int(input())
k = 0
lbound = -1
hbound = 10 ** 20
for i in range(1000):
	mid = (hbound + lbound) // 2
	ka = B * mid - a
	kb = S * mid - b
	kc = C * mid - c
	if money >= max(0, ka * pa) + max(0, kb * pb) + max(kc * pc, 0):
		k = max(mid, k)
		lbound = mid
	else:
		hbound = mid
print(k)
