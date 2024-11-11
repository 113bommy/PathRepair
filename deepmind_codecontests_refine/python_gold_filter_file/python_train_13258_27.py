s,n = map(int,input().split())
b=[]
for i in range(n):
    a = list(map(int,input().split()))
    b.append(a)
b.sort()
for i in b:
    if(s>i[0]):
        s+=i[1]
    else:
        print("NO")
        exit()
print("YES")