n,a=int(input()),[*map(int,input().split())]
for j in range(1,(n+1)//2):
    if n%j==0:
        for l in range(j):
            t=1
            for i in range(l,n,j):
                if a[i]==0:t=0;break
            if t:exit(print("YES"))
print("NO")