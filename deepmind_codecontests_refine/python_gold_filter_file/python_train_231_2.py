import math
t=int(input())
for _ in range(t):
    n=int(input())
    if n==1:
        print(0)
    else:
        var=n
        ans=0
        while var>0:
            if var==1:
                break
            elif var%6==0:
                var=var/6
            elif var*2<=1000000000:
                var=var*2
            else:
                ans=-1
                break
            ans+=1
        print(ans)
  