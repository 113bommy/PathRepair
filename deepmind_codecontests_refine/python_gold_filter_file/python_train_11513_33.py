li=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
m,n=map(int,input().split())
while m>0:
    p=0
    while p<n:
        print(li[p],end="")
        p+=1
        m-=1
        if m==0:
            break

