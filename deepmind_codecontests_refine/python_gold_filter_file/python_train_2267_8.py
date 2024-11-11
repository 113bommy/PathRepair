x,n=map(int,input().split())
l=sorted(list(map(int,input().split())))
ans=0
for i in range(102):
    if i not in l:
        if abs(x-i)<abs(x-ans):
            ans=i
print(ans)