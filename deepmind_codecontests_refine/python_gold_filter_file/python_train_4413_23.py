
n = int(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

su1 = 0
su = sum(l1)

#l3 = [(i-1) for i in l2]
l2.sort()
for i in range(l2[0]-1,l2[1]-1):
	su1 += l1[i]


su2 = su - su1
if su1 <= su2:
	print(su1)
else:
	print(su2)