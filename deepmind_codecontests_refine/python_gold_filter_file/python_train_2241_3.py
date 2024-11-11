import sys
input=sys.stdin.readline
l=input().split()
a=int(l[0])
b=int(l[1])
c=int(l[2])
d=int(l[3])
n=int(l[4])
l=[[0 for i in range(a+c)] for i in range(max(b,d))]
if(b>=d):
    for i in range(min(b,d),max(b,d)):
        for j in range(a,a+c):
            l[i][j]='.'
else:
    for i in range(min(b,d),max(b,d)):
        for j in range(a):
            l[i][j]='.'
currx=0
curry=0
curr=0
p=input().split()
li=[int(i) for i in p]
print("YES")
if(b>=d):
    if(d%2==0):
        curr=0
        for i in range(b):
            if(i%2==0):
                for j in range(a+c):
                    if(l[i][j]=='.'):
                        continue
                    l[i][j]=curr
                    li[curr]-=1
                    if(li[curr]==0):
                        curr+=1
            else:
                 for j in range(a+c-1,-1,-1):
                     if(l[i][j]=='.'):
                         continue
                     l[i][j]=curr
                     li[curr]-=1
                     if(li[curr]==0):
                         curr+=1
    else:
        curr=0
        for i in range(b):
            if(i%2==1):
                for j in range(a+c):
                    if(l[i][j]=='.'):
                        continue
                    l[i][j]=curr
                    li[curr]-=1
                    if(li[curr]==0):
                        curr+=1
            else:
                 for j in range(a+c-1,-1,-1):
                     if(l[i][j]=='.'):
                         continue
                     l[i][j]=curr
                     li[curr]-=1
                     if(li[curr]==0):
                         curr+=1
else:
    if(b%2==1):
        curr=0
        for i in range(d):
            if(i%2==0):
                for j in range(a+c):
                    if(l[i][j]=='.'):
                        continue
                    l[i][j]=curr
                    li[curr]-=1
                    if(li[curr]==0):
                        curr+=1
            else:
                 for j in range(a+c-1,-1,-1):
                     if(l[i][j]=='.'):
                         continue
                     l[i][j]=curr
                     li[curr]-=1
                     if(li[curr]==0):
                         curr+=1
    else:
        curr=0
        for i in range(d):
            if(i%2==1):
                for j in range(a+c):
                    if(l[i][j]=='.'):
                        continue
                    l[i][j]=curr
                    li[curr]-=1
                    if(li[curr]==0):
                        curr+=1
            else:
                 for j in range(a+c-1,-1,-1):
                     if(l[i][j]=='.'):
                         continue
                     l[i][j]=curr
                     li[curr]-=1
                     if(li[curr]==0):
                         curr+=1
for i in l:
    for j in i:
        if(j=='.'):
            print('.',end="")
        else:
            print(chr(97+j),end="")
    print()
