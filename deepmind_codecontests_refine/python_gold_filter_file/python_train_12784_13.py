n,x = map(int,input().split())
a = list(map(int,input().split()))
c = 1
b = 0
for i in a:
    b = i+b
    if b <= x:
        c+=1
print(c)