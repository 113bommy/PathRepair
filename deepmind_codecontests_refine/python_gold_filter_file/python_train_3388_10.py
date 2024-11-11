n,k=map(int,input().split())
ara=list(map(int,input().split()))
max=0
zero=0
value=0
end=0
for i in range(n):
    if ara[i]==0:
        zero+=1
    if zero<=k:
        max+=1
        end=i
    else:
        if ara[value]==0 :
            zero-= 1
        value+= 1
print(max)
for i in range(end-max+1,end+1):
    ara[i]=1
ch=''
for i in range(n):
    ch+=str(ara[i])+' '
print(ch[:-1])