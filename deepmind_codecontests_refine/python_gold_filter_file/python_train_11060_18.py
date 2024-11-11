t = int(input())

for i in range(0, t):
    length = int(input())
    
    listA = []
    if length % 4 != 0:
        print("NO")
        
    else:
        print("YES")
        
        sumB = 0
        for i in range(0, (length//2)):
            listA.append((i + 1) * 2)
        
        
        for y in range(0, (length//2) - 1):
            listA.append((y * 2) + 1)
        
    
        listA.append( (length // 4) * 2 + 2 + listA[-1])
        
        print(*listA)