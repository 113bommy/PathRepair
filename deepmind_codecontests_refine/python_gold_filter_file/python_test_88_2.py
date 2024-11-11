t = int(input())

for tc in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    if n %2 == 0 : print("YES")
    else :
        isIncr = True
        for i in range(1, n): 
            if a[i] <= a[i-1]:
                isIncr = False
                break
        if isIncr : print("NO")
        else: print("YES")
