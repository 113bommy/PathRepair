n,k = map(int,input().split())
c = 0
while n >0:
    n = n//k
    c +=1
print(c)