n=int(input())
j=0
for i in range(n):
    l=list(map(int, input().split()))
    if(sum(l)>=2):
        j+=1
print(j)