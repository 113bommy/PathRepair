for _ in range(int(input())):
    
    p=input()
    h=input()
    pl=len(p)
    ph=len(h)
    if ph<pl:
        print("NO")

    else:
        if ph==pl:
            if sorted(h)==sorted(p):
                print("YES")
            else:
                print("NO")
        else:
            fl=0
            for i in range(ph):
               if h[i] in p:           #similar letter in p
                    fl=0
                    #print(h[i:i+pl])
                    if sorted(h[i:i+pl]) == sorted(p):
                        fl=1
                        break
            if fl:
                print("YES")
            else:
                print("NO")
