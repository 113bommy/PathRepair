for _  in range(int(input())):
    a=input()
    ac=bc=cc=0
    for i in a:
        if i=='A':
            ac+=1
        elif i=='B':
            bc+=1 
        elif i=='C':
            cc+=1 
    if ac+cc==bc:
        print("YES")
    else:
        print("NO")