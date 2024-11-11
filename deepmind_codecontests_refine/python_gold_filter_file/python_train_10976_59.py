n,m=map(int,input().split())
l = list(map(int,input().split()))
a = 0
for i in l:
    if((5-m) >= i):
        a+=1
print(a//3)