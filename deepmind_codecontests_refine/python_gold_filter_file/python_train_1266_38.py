def f(n):return n if n == 1 else f(n-1)+(n-1)*4
print(f(int(input())))