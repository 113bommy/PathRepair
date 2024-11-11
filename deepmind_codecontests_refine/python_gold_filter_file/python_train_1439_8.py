def memorize(func):
    memo = {}
    def wrapper(*args):
        if args not in memo:
            memo[args] = func(*args)
        return memo[args]
    return wrapper

@memorize
def amida(W):   # W本の棒に対する1行アミダの引き方
    if W<2:
        return 1
    else:
        return amida(W-1)+amida(W-2)

@memorize
def amida2(H, W, x):
    if H==0:
        return 1 if x==1 else 0
    a = 0 if x==1 else amida(x-2)*amida(W-x)*amida2(H-1, W, x-1)
    b = amida(x-1)*amida(W-x)*amida2(H-1, W, x)
    c = 0 if x==W else amida(x-1)*amida(W-x-1)*amida2(H-1, W, x+1)
    return (a+b+c)%1000000007
print(amida2(*map(int, input().split())))