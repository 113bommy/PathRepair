n,v=map(int,input().split())
store=[]
for k in range(n):
    for x in list(map(int,input().split()))[1:]:
        if(v>x):
            store.append(k+1)
store=sorted(list(set(store)))
print(len(store))
print(*store)
