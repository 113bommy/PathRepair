t = int(input())
for _ in range(t):
    x,y = map(int,input().split(' '))
    a,b = map(int,input().split(' '))

    cost1 = min(x,y) * b + abs(x-y) * a
    cost2 = abs(x-y)*a + min(x,y)*2*a

    print(min(cost1,cost2))
    