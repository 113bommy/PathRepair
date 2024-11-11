n = int(input())
if n==0:
    print(1)
    exit()
print((3**(n-1))%(10**6+3))    