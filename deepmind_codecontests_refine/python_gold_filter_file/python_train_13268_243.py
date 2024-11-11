n=0
for i in range(int(input())):
    p,q=map(int,input().split())
    if q-p>=2:
        n+=1
print(n)