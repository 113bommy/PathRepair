n, m = map(int, input().split())
if(n>=m):
    print(int(m/n)-1)
else:
    t = m/(n)
    if(t%1 != 0 and t < 1):
        print("-1")
    else:
        x=0
        y=0
        while(t>1):
            if(t%3==0):
                t/=3
                y+=1
            elif(t%2==0):
                t/=2
                x+=1
            else:
                print("-1")
                break
        else:
            print(x+y)
