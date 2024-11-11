
k = int(input())
org =['c','o','d','e','f','o','r','c','e','s']
if k == 1 :
    print('codeforces') 
else :
    n = 1
    i = 2
    j = 1
    ans = ""
    ans2 = ""
    cont = True
    while cont :
        for s in range(1,11) :
            n = n * i // j
            if k <= n :
                dup = org[:s]
                dup2 = org[s:]
                for z in dup :
                    ans += z*i
                for z in dup2 :
                    ans2 += z*j
                print(ans + ans2)
                cont = False
                break
        i += 1
        j += 1    
