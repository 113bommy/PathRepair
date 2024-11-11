n,m=map(int,input().split())
ls=[]
for i in range(m):
    d,h=map(int,input().split())
    ls.append([d,h])
ls.sort()
max_h=0
flag=True
max_h=max(max_h,ls[0][0]-1+ls[0][1])
max_h=max(max_h,n-ls[m-1][0]+ls[m-1][1])
for i in range(m-1):
    max_h=max(max_h,ls[i][1])
    if(ls[i+1][1]-ls[i][1]>ls[i+1][0]-ls[i][0] or ls[i][1]-ls[i+1][1]>ls[i+1][0]-ls[i][0]):
        flag=False
        break
    else:
        x=(ls[i+1][1]-ls[i][1]+ls[i+1][0]-ls[i][0])//2
        max_h=max(max_h,x+ls[i][1])
max_h=max(max_h,ls[m-1][1])        
if(flag):print(max_h)
else:print("IMPOSSIBLE")