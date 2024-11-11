# n = 10000
# a = [1]*n 
# s = set()
# for i in range(2, n):
# 	if a[i]:
# 		s.add(i)
# 		for j in range(i, n, i):
# 			a[j] = 0

# def solve():
# 	tong = 0
# 	lst = list(s)
# 	num = int(input())
# 	for i in range(num):
# 		print(lst[i], end = ' ')
# 		tong += lst[i]

# 	print()
# 	print(tong)
def solve():
	tong = 0
	n = int(input())
	for i in range(2, n+2):
		print(i, end = ' ')
		tong += i
	print()
	# print(tong)

for i in range(int(input())):
	solve()
#Đào Xuân Hoàng Tuấn
