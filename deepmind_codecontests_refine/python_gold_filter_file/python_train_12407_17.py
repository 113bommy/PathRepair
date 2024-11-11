n=int(input())
s=input()
a_l=[]
b_l=[]
for _ in range(n):
    a,b=map(int,input().split())
    a_l.append(a)
    b_l.append(b)
#c=[[0 for _ in range(50)] for _ in range(n)]
#l=0
cnt=[0]*1001
for i in range(n):
    a,b=a_l[i],b_l[i]
    fg=0
    if s[i]=='1':
        fg=1
    for j in range(1001):
        if j-b>=0 and (j-b)%a==0:
            fg=(fg+1)%2
        #c[i][j]=fg
        if fg==1:
            cnt[j]+=1
print(max(cnt))

