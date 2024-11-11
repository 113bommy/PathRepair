t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    
    l.sort()
    
    c=0
    for i in range(1,len(l)):
        if l[i]>l[i-1]:
            c+=1
    print(c+1)