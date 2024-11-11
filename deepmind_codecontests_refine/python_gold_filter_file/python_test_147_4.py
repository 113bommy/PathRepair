t = int(input())
for i in range(t):
    s = input()
    S = [ch for ch in s]
    cnt = 0 
    for ch in s:
        if ch == 'N':
            cnt +=1 
        
    if len(s) == 2:
        if s == 'EE' or s == 'NN':
            print("YES")
        else:
            print("NO")
    elif cnt == 1:
        print("NO")
    
    else:
        print("YES")