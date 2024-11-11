n,x = [int(x) for x in input().split()]
check = 0
if n * n < x:
    print(0)
else:
    for i in range(1,int(pow(x,0.5)+1)):
        if x % i == 0 and x != i*i and x / i <= n:
            check += 2
        elif x % i == 0 and x == i * i and x / i <= n:
            check += 1
    print(check)
