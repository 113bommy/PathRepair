def mi():return map(int,input().split())
def li():return list(mi())
def ii():return int(input())
def si():return input()
n,m=mi()
a=[]
for i in range(n):
    a.append(list(si()))
c=0
for i in range(n):
    for j in range(m):
        if(a[i][j]=='W'):
            if(i-1>=0 and a[i-1][j]=='P'):
                c+=1
                continue
            if(j-1>=0 and a[i][j-1]=='P'):
                c+=1
                continue
            if(i+1<n and a[i+1][j]=='P'):
                c+=1
                continue
            if(j+1<m and a[i][j+1]=='P'):
                c+=1
                continue
print(c)
            