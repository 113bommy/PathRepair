# import sys
# sys.stdin = open('input.txt', 'r')

# n = int(input())
# s = input()

# a = 0
# d = 0

# for i in s:
# 	if i == 'A':
# 		a = a+1
# 	else:
# 		d += 1

# if a>d: print('Anton')
# elif a<d: print('Danik')
# else: print('Friendship')

n, h = [ int(i) for i in input().split() ]

a = [ int(i) for i in input().split() ]

width = 0

for i in a:
	if i<=h:
		width = width+1
	else:
		width = width+2
print(width)