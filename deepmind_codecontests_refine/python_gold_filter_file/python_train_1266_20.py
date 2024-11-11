def rom(n):
    if n==1:
        return 1
    return (n-1)*4+rom(n-1)
n = int(input())
print(rom(n))