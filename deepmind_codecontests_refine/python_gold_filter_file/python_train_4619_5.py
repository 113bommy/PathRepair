n=int(input())
arr2=[]
p=0
for i in range(n):
    arr2=list(map(int, input().split()))
    m=0
    for elem in arr2:
        if elem==1:
            m=m+1
    if m==2 or m==3:
        p=p+1 
    
print(p)  