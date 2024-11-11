from bisect import bisect_left as bl
import heapq as hp
n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
for j in range(40,-1,-1):
    c=0
    
    for i in range(n):
        if (1<<j)&a[i]>0:
            ind=i
            c+=1
    if c==1:
        print(a[ind],end=" ")
        for p in range(n):
            if p!=ind:
                print(a[p],end=' ')
        exit()        
print(*a)        