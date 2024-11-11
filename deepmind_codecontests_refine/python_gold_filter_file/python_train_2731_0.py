t=int(input())
for i in range(0,t):
    a=[]
    k=0
    for j in range(0,9):
        a.append(input())
        a[j]=list(a[j])
        if(a[j][k%9]!='9'):
            a[j][k%9]=str(int(a[j][k%9])+1)
            
            k+=4
        else:
            a[j][k%9]='1'
            
            k+=4
    for j in range(0,9):
        for tyu in range(0,9):
            print(a[j][tyu],end="")
        print("")

    