n, v = map(int, input().split())
cost = v -  1
if(v >= (n-1)):
    print(n-1)
else:
    for x in range(1, n-v+1):
        cost += x
    print(cost)