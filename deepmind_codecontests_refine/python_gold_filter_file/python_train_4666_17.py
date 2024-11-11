city={1:0, 2:0, 3:0, 4:0}
for _ in range(3):
    a,b=map(int, input().split())
    city[a]+=1
    city[b]+=1
    
if list(city.values()).count(2)==2:
    print("YES")
else:
    print("NO")