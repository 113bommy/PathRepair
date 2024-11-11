t =int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    if sum(a)%n==0:
        print(0)
    else:
        print(1)