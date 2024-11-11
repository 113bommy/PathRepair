t=int(input())
ans=""
for i in range(t):
    b=list(map(int,input().split()))
    a1=b[0]
    a2=b[1]
    a3=b[6]-b[0]-b[1]
    ans+=str(a1)+" "+str(a2)+" "+str(a3)+"\n"
print(ans)

    
    