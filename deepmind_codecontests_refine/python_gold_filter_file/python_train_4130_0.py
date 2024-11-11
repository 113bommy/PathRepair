n=int(input())
a=list(map(int,input().split()))
b=[]
while a:
    r=a.pop()
    b.insert(0,r)
    while r in a:
        a.remove(r)
print(len(b))
for i in b:
    print(i,end=' ')