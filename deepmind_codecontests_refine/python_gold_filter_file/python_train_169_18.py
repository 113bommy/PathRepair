n=int(input())
#arr=list(map(int,input().split()))
s=input()

d={}
maxv=0
maxs=''
for i in range(n-1):
    try:
        d[s[i:i+2]]+=1
    except:
        d[s[i:i+2]]=1

    if d[s[i:i+2]]>maxv:
        maxv=d[s[i:i+2]]
        maxs=s[i:i+2]
print(maxs)
    
       


