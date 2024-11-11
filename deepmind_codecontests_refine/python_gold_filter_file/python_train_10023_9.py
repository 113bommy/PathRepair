t = int(input())


for i in range(t):
    tp = []
    k, sz = list(map(int, input().split()))
    

    for i in range(k):
        a, b = list(map(int, input().split()))
        c, d = list(map(int, input().split()))
        tp.append((a, b, c, d))
        #print(a, b, c, d)
        
        
    if sz%2==1:
        print("NO")
        continue 
    a = False
    b = False
    
    for i in range(len(tp)):
        for j in range(i, len(tp)):
            if not a and (tp[i][0] == tp[j][0] and tp[i][3] == tp[j][3] and tp[i][1] == tp[j][2] and tp[i][2] == tp[j][1]):
                # print("find ", i, j)
                a = True
                break
        if tp[i][2] == tp[i][1]:
            b = True
        if a and b:
            break
    
    if a and b:
        print("YES")
    else:
        print("NO")