K=int(input())
n=0
an=0
for i in range(K+10):
    n+=1
    an=(10*an+7)%K
    if an==0:
        print(n)
        exit()
print(-1)
