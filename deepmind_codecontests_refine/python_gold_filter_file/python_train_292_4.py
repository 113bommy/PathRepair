N = int(input())
p = list(map(int,input().split()))

c=0
i=0
while(i<N):
    if p[i] == i+1:
        c+=1
        i+=1
    i+=1
print(c)
