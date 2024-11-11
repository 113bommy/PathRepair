n=int(input())
l = list(map(int,input().split()))

    
k=[]
a = set(l)
for i in a:
    k.append(i)
# print(*k)
k.sort()
if len(k)==1:
    print("NO")
else:
    print(k[1])
    