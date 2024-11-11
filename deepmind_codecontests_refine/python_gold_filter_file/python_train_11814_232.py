inp = input().strip().split()
m = int(inp[0])
n = int(inp[1])
if m%2==0 and n%2==0:
    max1 = (m//2)*n
    max2 = (n//2)*m
    if max1 > max2:
        print(max1)
    else :
        print(max2)

elif m%2==0 and n%2!=0:
    print((m//2)*n)
elif m%2!=0 and n%2==0:
    print((n//2)*m)
else:
    max1 = (m//2)*n + (n//2)
    max2 = (n//2)*m + (m//2)
    if max1 > max2:
        print(max1)
    else :
        print(max2)

