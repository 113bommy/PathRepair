n=int(input())
l=list(map(int,input()))
f=list(map(int,input().split()))
out=[]
flag=0
flag2=0
for i in l:
    #print(i,f[i-1],flag,flag2)
    if i<=f[i-1] and flag2==0:
        out.append(f[i-1])
        if i!=f[i-1]:
            flag=1
    else:
        out.append(i)
        if flag==1:
            flag2=1
for i in out:
    print(i,end='')
print()