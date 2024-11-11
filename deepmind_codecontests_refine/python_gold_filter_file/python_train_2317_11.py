from sys import stdin
 
inp = stdin.readline
 
t = int(inp())
 
for _ in range(t):
    n = int(inp())
    n *= 2
    a = [int(x) for x in inp().split()]
    
    oddIndices = []
    evenIndices = []
    nOdd = 0
    nEven = 0
    for i in range(n):
        if a[i] %2:
            nOdd +=1
            oddIndices.append(i+1)
        else:
            nEven +=1
            evenIndices.append(i+1)
    if nOdd%2 and nEven%2:
        o = oddIndices.pop()
        e = evenIndices.pop()
        for i in range(1,len(oddIndices),2):
            print(oddIndices[i],oddIndices[i-1])
        for i in range(1,len(evenIndices),2):
            print(evenIndices[i],evenIndices[i-1])
    elif nOdd > 0:
        o = oddIndices.pop()
        o = oddIndices.pop()
        for i in range(1,len(oddIndices),2):
            print(oddIndices[i],oddIndices[i-1])
        for i in range(1,len(evenIndices),2):
            print(evenIndices[i],evenIndices[i-1])
    elif nEven > 0:
        o = evenIndices.pop()
        o = evenIndices.pop()
        for i in range(1,len(oddIndices),2):
            print(oddIndices[i],oddIndices[i-1])
        for i in range(1,len(evenIndices),2):
            print(evenIndices[i],evenIndices[i-1])