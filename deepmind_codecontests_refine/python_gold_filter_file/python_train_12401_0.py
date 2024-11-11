import sys
input=sys.stdin.readline
n,c=map(int,input().split())
ar=list(map(int,input().split()))
br=[]
count=0
for i in range(n):
    if(ar[i]==c):
        count+=1
    br.append(count)
dic={}
for i in range(n):
    if(ar[i]!=c):
        if(ar[i] in dic):
            dic[ar[i]].append(i)
        else:
            dic[ar[i]]=[i]


ans=0
for i in dic:
    le=len(dic[i])
    if(le==1):
        ans=max(ans,1)
    else:
        ans=max(ans,1)
        su=0
        flag=False
        for j in range(1,le):
            r=dic[i][j]
            l=dic[i][j-1]
            if(flag):
                su+=1-(br[r]-br[l])
            else:
                flag=True
                su+=2-(br[r]-br[l])
            ans=max(ans,su)
            if(su<=0):
                flag=False
                su=0

print(br[-1]+ans)