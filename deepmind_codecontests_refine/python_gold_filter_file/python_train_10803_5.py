a=int(input())
ans = 0
tmp = 2 
while tmp*tmp <=a:
    ct = 0 
    while not a % tmp:
        ct+=1
        a/=tmp
    for i in range(1,ct+1):
        if (1+i)*i/2<=ct:
            ans+=1
        else:
            break
    tmp+=1
if a != 1:
    ans+=1
print(ans)