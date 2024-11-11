for _ in range(int(input())):
    n = int(input())
    ans1=[]
    ans2=[]
    i=1
    while i<=n**0.5:
        k = n//i
        ans1.append(k)
        ans2.append(i)
        i+=1
    if ans1[-1]==ans2[-1]:
        ans1.pop()
    print(len(ans1)+len(ans2)+1)
    print(0,end=' ')
    for i in ans2:
        print(i,end=' ')
    for i in ans1[::-1]:
        print(i,end=' ')
    print()
        
    