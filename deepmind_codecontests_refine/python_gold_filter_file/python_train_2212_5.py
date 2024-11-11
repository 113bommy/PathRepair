for _ in range(int(input())):
    n = int(input())
    s= list(map(int, input().split()))
    s.sort()
    odd,even=0,0
    f=False
    c=0
    for i in range(n-1):
        if s[i+1]-s[i] == 1:
            c+=1
            if i==n:
                f=True
        if s[i]%2:
            odd+=1
        else:
            even+=1
    if not f:
        if s[n-1]%2:
            odd+=1
        else:
            even+=1
    odd = odd-c
    even = even-c
    #print(odd,even,c)
    if (odd%2==0 and even%2==0) or (odd%2==1 and even%2==1 and c>0) :
        print("YES")
    else:
        print("NO")