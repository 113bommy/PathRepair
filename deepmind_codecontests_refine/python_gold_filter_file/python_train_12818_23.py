n, x, y = list(map(int, input().split()))
doors = list(map(int, input().split()))

possible = 0
repair = 0

for i in range(len(doors)):
    if doors[i] <= x:
        possible+=1 
    
if x > y:
    print(n)
else:
    print(int((possible+1)/2))