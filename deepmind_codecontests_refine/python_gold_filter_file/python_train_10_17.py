t=int(input())
while (t):
    t=t-1
    a,b,c=input().split()
    a=int(a);b=int(b);c=int(c)
    i=int(c);
    if c<a or c>b:
        print(c)
    else:
        if c*2>=a:
            i=b-b%c;
        while(1):
            i=i+c
            if i<a or i>b:
                print(i)
                break
           
    
