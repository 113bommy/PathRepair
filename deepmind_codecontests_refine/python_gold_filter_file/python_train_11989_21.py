IL = lambda: list(map(int, input().split()))

def f(x):
    return x*(x-1)//2

n = int(input())
N = sorted([input()[0] for i in range(n)])
c1, c2 = N[::2], N[1::2]
print(sum(f(c1.count(l)) for l in set(c1)) + sum(f(c2.count(l)) for l in set(c2)))