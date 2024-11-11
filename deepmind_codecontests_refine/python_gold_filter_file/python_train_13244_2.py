from math import ceil 
for _ in range(int(input())):
    a, b = map(int,input().split())
    mini = int(1e9)
    for x in map(int,input().split()):
        z = ceil(b/x)
        if x <= b:
            mini = z if mini > z else mini
        else:
            mini = 2 if mini > 2 else mini
            

    print(mini)
            
