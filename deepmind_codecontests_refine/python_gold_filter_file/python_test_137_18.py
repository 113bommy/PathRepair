def check(a, b):
    if a not in b:
        return False

    # b = b[:b.find(a)] + b[b.find(a)+1:]

    left = b[:b.find(a)]
    right = b[b.find(a)+len(a):]

    if '0' in left or '0' in right:
        return False

    return True

x, y = map(int,input().split())

a = bin(x)[2:]
b = bin(y)[2:]
if(a==b):
    print("YES")
    exit()

if check(a+'1',b) or check(a.strip('0'),b):
    print("YES")
elif check((a+'1')[::-1],b) or check(a.strip('0')[::-1],b):
    print("YES")
else:
    print("NO")