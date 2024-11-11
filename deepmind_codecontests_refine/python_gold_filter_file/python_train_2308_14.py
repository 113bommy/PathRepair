a,b,c,d=[int(x) for x in input().split()]
k = sorted([a,b,c])
if k[1]-k[0]>=d and k[2]-k[1]>=d:
    print("0")
elif k[1]-k[0]>=d and k[2]-k[1]<d:
    print(abs(d-(k[2]-k[1])))
elif k[1]-k[0]<d and k[2]-k[1]>=d:
    print(abs(d-(k[1]-k[0])))
elif k[1]-k[0]<d and k[2]-k[1]<d:
    print(abs(d-(k[1]-k[0]))+abs(d-(k[2]-k[1])))