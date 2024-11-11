c,l=0,[]
for i in range(int(int(input()))):
    d=list(map(int,input().split()))
    if(1 not in d and 3 not in d):
        c=c+1
        l.append(i+1)
print(c)
print(*l)
