for _ in range(int(input())):
    x, y, z = map(int, input().split())
    x1, y1, z1 = map(int, input().split())
    ans = (min(z,y1) * 2) - (min(y,max(0,z1 - (max(z,y1) - min(z,y1)) - x))  * 2)
    k = min(z, y1) * 2
    k1 = max(z1-min(z+x-k//2,z1),0) * 2
    print(k-k1)