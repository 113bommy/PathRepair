n = int(input())
k = 0
for i in range(n):
    t,x,y = map(int,input().split())
    if t < x + y or t % 2 != (x + y) %2:
        print('No')
        break
    if i == n-1:
        print('Yes')