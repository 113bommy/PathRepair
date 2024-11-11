def func(n):
    for i in range(n):
        k = list(map(int,input().split()))
        a = k[0]
        b = k[1]
        if a == b:
            print(0)
        elif a>b and (a-b) % 2 == 0:
            print(1)
        elif a<b and (b-a) %2 != 0:
            print(1)
        else:
            print(2)
n = int(input())
func(n)