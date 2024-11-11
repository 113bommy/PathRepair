x,y = map(int, input().split())
z = int(input())
li = [0]*6
li[0] = x-y
li[1] = x 
li[2] = y
for i in range(3,6):
	li[i] = li[i-1]- li[i-2]
print(li[z%6]%(10**9+7))
