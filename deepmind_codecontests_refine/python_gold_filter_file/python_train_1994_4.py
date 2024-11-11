n = int(input())
l= list(map(int, input().rstrip().split(" ")))
l.sort()
z = list(set(l))
lz= len(z)
if  lz==1:
    print(0)
elif lz==2:
    if abs(z[1]-z[0])%2:
        print(abs(z[1]-z[0]))
    else:
        print(abs(z[1] - z[0])//2)
elif lz>3:
    print(-1)
else:
    if abs(z[0] - z[1]) == abs(z[1]-z[2]):
        print(abs(z[0] - z[1]))
    else:
        print(-1)