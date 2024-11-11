T = int(input().strip())
for t in range(T):
    s,i,n = [int(x) for x in input().strip().split()]
    #res = max(int((n+s-i)/2.0+0.5),0)
    #if s-i>n:
        #print(n+1)
    if (n+s-i)%2==0:
        res = (n+s-i)/2
    else:
        res = (n+s-i+1)/2
    print(max(min(int(res),n+1),0))
