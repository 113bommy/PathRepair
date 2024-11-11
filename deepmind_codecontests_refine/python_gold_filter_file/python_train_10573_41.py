k2,k3,k5,k6 = map(int,input().split())
a = min(k2,k5,k6)
b = min(k3,k2 - min(k2,k5,k6))
print(a*256+b*32)
