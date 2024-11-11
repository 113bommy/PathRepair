a=int(input())




t= list(map(int,input().split()))

t.sort()


if sum(t)/a>=4.5:
    print(0)
else:
    
    for k in range(a):
        t[k]=5
        if sum(t)/a>=4.5:
            print(k+1)
            break
        
    



