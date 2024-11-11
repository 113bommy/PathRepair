N=int(input())
x=7%N
for i in range(1,N+1):
    if x==0:
        print(i)
        exit()
    x=(x*10+7)%N
print(-1)
