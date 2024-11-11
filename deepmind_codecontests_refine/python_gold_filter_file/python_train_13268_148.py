t=int(input())
count=0
for it in range(t):
    a,b=map(int,input().split())
    if(b-a>=2):
        count+=1
print(count)