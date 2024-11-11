from sys import stdin,stdout
def bn(x):
    print(bin(x)[2:])
ss=set()
for i in range(1,30):
    ss.add((1<<i)-1)
# print(ss)
for _ in range(1):#int(stdin.readline())):
    n=int(stdin.readline())
    # a=list(map(int,stdin.readline().split()))
    op=0;ans=[]
    while n not in ss:
        op+=1
        # bn(n)
        if op&1:
            p=-1
            for i in range(22):
                if (n>>i)&1:
                    p=i
            ans+=[1+p]
            n=n^((1<<(1+p))-1)
        else:n+=1
    print(op)
    print(*ans)