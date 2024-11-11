v1,v2,v3,vm=[int(x) for x in input().split()]
if(vm<=2*v3 and vm<v2 and 2*vm>=v3):
    c3=v3
    c2=v2
    
    for i in range(v3,v2+1):
        if(c3<=2*v3 and c3<v2 and c3<=2*vm and c3>=vm):
            break
        else:
            c3+=1
    j=max(v2,2*vm)
    for i in range(j+1):
        if(c2<=2*v2 and c2>2*v3 and c2>2*vm):
            break
        else:
            c2+=1
    
    if(v1>2*v3 and v1>2*v2):
        print(v1)
    else:
        print(v1*2)
    print(c2)
    print(c3)
else:
    print(-1)
    
    