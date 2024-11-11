


t = int(input())


while(t!=0):
    l = [int(i) for i in input().split()]
    ans = l[0]
    for i in range(1,l[1]):
        c = str(l[0])
        if int(min(c)) == 0:
            break
        else:
            ans = l[0] + int(max(c))*int(min(c))
            l[0] = ans
        
    if(l[1] == 1):
        print(l[0])
    else:
        print(ans)
    t = t-1




    
