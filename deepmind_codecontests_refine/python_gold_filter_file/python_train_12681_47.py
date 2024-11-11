s,t=input(),input()
m,n=len(s),len(t)
l=[[0 for i in range(n+1)] for j in range(m+1)]
for i in range(1,m+1):
    for j in range(1,n+1):
        if s[i-1]==t[j-1]:
            l[i][j]=l[i-1][j-1]+1
        else:
            l[i][j]=max(l[i-1][j],l[i][j-1])
pos=l[m][n]
i,j,lcs=m,n,['']*(pos+1)
while i>0 and j>0:
    if s[i-1] == t[j-1]:
        lcs[pos-1]=s[i-1]
        i,j,pos=i-1,j-1,pos-1
    elif l[i-1][j]>l[i][j-1]:
        i-=1
    else:
        j-=1
print(''.join(lcs))
