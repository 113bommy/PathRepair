def solve():
    input()
    m,n=list(map(int,input().split()))
    p=[]
    for _ in range(m):
        p.append(list(map(int,input().split())))
    
    def ops(num):
        flag=True
        temp=[0 for _ in range(m)]

        for j in range(n):
            tmp=0
            for i in range(m):
                if p[i][j]>=num:
                    temp[i]+=1
                    tmp=1
            if tmp==0:flag=False
        #print('test',num,flag,temp)
        return True if flag and max(temp)>=2 else False
    
    l,r=0,10**9+1
    while r-l>1:
        mid=l+r>>1
        if ops(mid):l=mid
        else:r=mid
    print(l)

for _ in range(int(input())):solve()