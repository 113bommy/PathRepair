n=int(input())
l=list(map(int,input().split()))
for i in range(n):
    count=0
    for j in range(n):
        if(l[i]<l[j]):
            count+=1
    print(count+1,end=' ')
