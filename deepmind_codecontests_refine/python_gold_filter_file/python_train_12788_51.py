A,B,C,D,E,F = map(int,input().split())
solve = E/(100+E)
ans = [0,0,0]
for i in range(int(F//100//A)+1):
    for j in range(int((F-A*100*i)//100//B)+1):
        for k in range(int((F-A*100*i-B*100*j)//C)+1):
            for l in range(int((F-A*100*i-B*100*j-C*k)//D)+1):
                if  i!=0 or j!=0:
                    can = (C*k+D*l)/(A*100*i+B*100*j+C*k+D*l)
                    if solve>=can>=ans[0]:
                        
                        ans[0],ans[1],ans[2] = can,A*100*i+B*100*j+C*k+D*l,C*k+D*l

print(ans[1],ans[2])