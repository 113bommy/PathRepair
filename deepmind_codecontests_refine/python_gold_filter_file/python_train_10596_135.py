N,K = map(int,input().split())
C = 0
while N >0:
    N = N//K
    C +=1
print(C)