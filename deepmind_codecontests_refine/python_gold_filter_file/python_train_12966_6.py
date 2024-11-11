a,b=map(int,input().split())
z_row=[0]*(a+1)
z_col=[0]*(a+1)
z_row1=0
z_col1=0
s=a*a;o=""
for _ in " "*b:
    k=0
    x,y=map(int,input().split())
    if z_row[x]==0:
        s-=(a-z_col1)
        k=-1
    if z_col[y]==0:
        s-=(k+a-z_row1)
    if z_row[x]==0:z_row1+=1
    if z_col[y]==0:z_col1+=1
    z_row[x]=1
    z_col[y]=1
    o+=str(s)+" "
print(o)