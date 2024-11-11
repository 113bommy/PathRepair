n=int(input())
if(n==0):
    print("1")
else:
    ans=int(3**(n-1))
    ans=ans%(1000003)
    print(ans)