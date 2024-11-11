t = int(input())
while t>0:
    n = int(input())
    if(n<4):
        print(-1)
        t-=1
        continue
    ans =[]
    for x in range(n//4):
        ans+=[4*x+2,4*x+4,4*x+1,4*x+3]
    if(n%4 == 1):
        ans +=[n]
    elif n%4 ==2:
        ans = ans[0:-1]+[n-1]+[ans[-1]]+[n]
    elif n%4 == 3:
        ans = ans[0:-1]+[n-2] +  [n] + [ans[-1]]+ [n-1]
    print(*ans)
    t-=1