n=int(input())
l=list(map(int,input().split()))
for i in range(n//2):
    if i%2==0:
        l[i],l[-i-1]=l[-i-1],l[i]
print(*l)