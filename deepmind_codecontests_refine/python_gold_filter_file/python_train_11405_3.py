import math
#t=int(input())
#lst = list(map(int, input().strip().split(' ')))
n,m = map(int, input().strip().split(' '))
lst=[0]*n
time=[10000]*n
for i in range(m):
    l,r,t,c = map(int, input().strip().split(' '))
    for j in range(l,r+1):
        if t<time[j-1]:
            time[j-1]=t
            lst[j-1]=c
print(sum(lst))
        
    
        
     
    

