a, b, n = (int(i) for i in input().split())
if a%b == 0 or (a*10)%b == 0:
    print(a*(10**n))
elif ((a*10)+1)%b == 0:
    print(((a*10)+1)*(10**(n-1)))
elif ((a*10)+2) % b == 0:
    print(((a*10)+2)*(10**(n-1)))
elif ((a*10)+3) % b == 0:
    print(((a*10)+3)*(10**(n-1)))
elif ((a*10)+4) % b == 0:
    print(((a*10)+4)*(10**(n-1)))
elif ((a*10)+5) % b == 0:
    print(((a*10)+5)*(10**(n-1)))
elif ((a*10)+6) % b == 0:
    print(((a*10)+6)*(10**(n-1)))
elif ((a*10)+7) % b == 0:
    print(((a*10)+7)*(10**(n-1)))
elif ((a*10)+8) % b == 0:
    print(((a*10)+8)*(10**(n-1)))
elif ((a*10)+9) % b == 0:
    print(((a*10)+9)*(10**(n-1)))
else:
    print(-1)
