for i in range (int(input())):
    n=int(input())
    n1=n
    l1=list(map(int,input().split()))
    c1=0
    for j in range (n1):
        m1=max(l1)
        if(l1.index(m1)!=0 and l1.index(m1)!=len(l1)-1):
            print("YES")
            print(l1.index(m1)+c1,l1.index(m1)+c1+1,l1.index(m1)+2+c1)
            break
        elif(l1.index(m1)==0):
            c1+=1
            l1.remove(m1)
        elif(l1.index(m1)==len(l1)-1):
            l1.remove(m1)
        if(len(l1)<3):
            print("NO")
            break
        