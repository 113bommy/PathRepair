for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    c = sum(l)
    if l[-1]>c-l[-1]:
        print("T")
    else:
        if sum(l)%2 == 1:
            print("T")
        else:
            if len(l) == 1:
                print("T")
            else:
                print("HL")
        
        
        
