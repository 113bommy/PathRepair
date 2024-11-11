q=int(input())
f=[]
t='RGB'*(2000//3 + 1)
for i in range(q):
    n,k=map(int,input().split())
    s=input()
    s1=t[:k]
    s2=t[1:k+1]
    s3=t[2:k+2]
    mi=k
    for i in range(n+1-k):
        num=[0,0,0]
        for j in range(k):
            if s[i+j]==s1[j]:
                num[1]+=1
                num[2]+=1
            elif s[i+j]==s2[j]:
                num[0]+=1
                num[2]+=1
            else:
                num[0]+=1
                num[1]+=1
        u=min(num)
        if u<mi:
            mi=u
    f+=[mi]
for i in f:
    print(i)