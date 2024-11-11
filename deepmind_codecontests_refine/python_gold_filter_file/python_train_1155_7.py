


n = int(input())

t= list(map(int,input().split()))


p=t[0]

if n>1:
    for j in range(1,n):
        p+=(t[j]-1)*(j+1)+1

print(p)
