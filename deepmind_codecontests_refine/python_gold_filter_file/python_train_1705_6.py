# import sys
# sys.stdin = open("F:\\Scripts\\input","r")
# sys.stdout = open("F:\\Scripts\\output","w")


MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

n , m = I()
x = n
y = 0
l = []
while x >= 0 and y <= m:
	l.append([x,y])
	x -= 1
	y += 1
# if x <= n and y > m:
# 	l.append([x,0])
print(len(l))
for i in l:
	print(*i)