n, m = map(int, input().split())
def func(n, num): 
    if num == 1:
        return 1
    else:
        for i in range(num//n ,0,-1):
            if num % i == 0:
                return i
print(func(n,m))
