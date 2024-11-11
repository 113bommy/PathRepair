n=int(input())
for x in range(n):
    l=list(map(int,input().split()))
    if(l[0]%2!=0):
        if((l[1]-l[0]+1)%2!=0):
            ans=((l[1]-l[0])//2)+((l[1])*(-1))
        else:
            ans=(l[1]-l[0]+1)//2
    else:
        if((l[1]-l[0]+1)%2==0):
            ans=((l[1]-l[0]+1)//2)*(-1)
        else:
            ans=((l[1]-l[0]+1)//2)*(-1)+l[1]
    print(ans)
