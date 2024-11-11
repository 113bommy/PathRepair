n = int(input())
l =list(map(int,input().split()))
l.reverse()
a = [0]*(max(l)+1)
for i,j in enumerate(l):
    if a[j]==0:
        a[j]=i+1
print(a.index(max(a)))    
    
    
    
    
