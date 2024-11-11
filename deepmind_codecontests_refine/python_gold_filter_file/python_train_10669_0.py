n=int(input());l=list(map(int,input().split()))
for i in range(n):
    c=0
    for j in range(n):
        if l[j]>l[i]:
            c+=1
    print(c+1,end=" ")