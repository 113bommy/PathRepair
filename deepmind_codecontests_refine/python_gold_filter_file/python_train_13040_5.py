for t in range(int(input())):
    n = int(input())    
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    temp1 = []
    temp2 = []
    common = 0
    unique = 0
    am = min(a)
    bm = min(b)
    for x in range(n):
        temp1.append(abs(a[x] - am))
        temp2.append(abs(b[x] - bm))
        common += min(temp1[x], temp2[x])
        unique += abs(temp1[x] - temp2[x])
    ans = common + unique
    print(ans)
        
        
        
        
        
    
        
    