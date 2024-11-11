n,v = map(int,input().split())
l1=[]

for i in range(n):
        l = list(map(int,input().split()))
        if(min(l[1:])<v):
            l1.append((i,min(l[1:])))
sorted(l1, key = lambda l1:l1[1])
print(len(l1))
for i in l1:
    print(i[0]+1,end= " ")            
            