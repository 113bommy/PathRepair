'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
def f1(a,b,c,d):
    global ans
    ans.append((a[1],a[2],b[1],b[2],c[1],c[2]))
    ans.append((a[1],a[2],b[1],b[2],d[1],d[2]))
    ans.append((a[1],a[2],d[1],d[2],c[1],c[2]))

def f2(a,b,c,d):
    global ans
    ans.append((a[1],a[2],b[1],b[2],d[1],d[2]))
    ans.append((a[1],a[2],d[1],d[2],c[1],c[2]))

def f3(a,b,c,d):
    global ans
    ans.append((a[1],a[2],d[1],d[2],c[1],c[2]))

t = int(input())
for _ in range(t):
    n,m=map(int,input().split())
    mat=[[0 for x in range(m)] for y in range(n)]
    for i in range(n):
        x=input()
        for j in range(m):
            mat[i][j]=int(x[j])
    ans=[]
    for i in range(n-1):
        for j in range(m-1):
            if i==n-2 and j==m-2:
                arr=[(mat[i][j],i,j),(mat[i+1][j],i+1,j),(mat[i][j+1],i,j+1),(mat[i+1][j+1],i+1,j+1)]
                arr=sorted(arr,key=lambda x:x[0],reverse=True)
                c=0
                for k in arr:
                    if k[0]:
                        c+=1
                if c==0:
                    continue
                elif c==1:
                    f1(arr[0],arr[1],arr[2],arr[3])
                elif c==2:
                    f2(arr[3],arr[0],arr[1],arr[2])
                elif c==3:
                    f3(arr[2],arr[3],arr[1],arr[0])
                else:
                    ans.append((i+1,j+1,i,j+1,i+1,j))
                    f1(arr[0],arr[1],arr[2],arr[3])
                continue
            if j==m-2:
                if mat[i][j] and mat[i][j+1]:
                    ans.append((i,j,i,j+1,i+1,j))
                elif (not mat[i][j]) and mat[i][j+1]:
                    ans.append((i+1,j+1,i,j+1,i+1,j))
                elif mat[i][j] and (not mat[i][j+1]):
                    ans.append((i,j,i+1,j,i+1,j+1))
                else:
                    continue
                for k in range(0,6,2):
                    mat[ans[-1][k]][ans[-1][k+1]]^=1
                continue
            if i==n-2:
                if mat[i][j] and mat[i+1][j]:
                    ans.append((i,j,i+1,j,i,j+1))
                elif (not mat[i][j]) and mat[i+1][j]:
                    ans.append((i+1,j+1,i,j+1,i+1,j))
                elif mat[i][j] and (not mat[i+1][j]):
                    ans.append((i,j,i,j+1,i+1,j+1))
                else:
                    continue
                for k in range(0,6,2):
                    mat[ans[-1][k]][ans[-1][k+1]]^=1
                continue
            if mat[i][j]:
                ans.append((i,j,i,j+1,i+1,j))
            else:
                continue
            for k in range(0, 6, 2):
                mat[ans[-1][k]][ans[-1][k + 1]] ^= 1
    stdout.write(str(len(ans))+'\n')
    for i in ans:
        for j in i:
            stdout.write(str(j+1)+" ")
        stdout.write('\n')