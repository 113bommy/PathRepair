for i in range(int(input())):
    t,e=map(int,input().split())
    if t==e:
        print(0)
    else:
        n=e-t
        if n>0:
            m=n%5
            p=(n-m)//5
            k=m%2
            j=(m-k)//2
            l=k%1
            u=(k-l)//1
            print(p+j+u)
            
        else:   
            m=n%-5
            p=(n-m)//-5
            k=m%-2
            j=(m-k)//-2
            l=k%-1
            u=(k-l)//-1
            print(p+j+u)
     