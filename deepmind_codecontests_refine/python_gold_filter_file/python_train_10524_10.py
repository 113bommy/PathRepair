n = int(input())
max=1
a = sum(map(int, input().split())) 
for j in range (2,n+1):
    b=sum(map(int, input().split())) 
    if(a<b):
        max+=1
        #print(max)
print(max)