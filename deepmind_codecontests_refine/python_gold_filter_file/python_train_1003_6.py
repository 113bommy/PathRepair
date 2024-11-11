def calc(a,n):
    i=0
    while(i<n-1):
        if(abs(a[i]-a[i+1])>1):
            return False
        i+=1
    return True
n=int(input())
a=list(map(int,input().split()))
if(calc(a,n)):
    print("YES")
else:
    print("NO")