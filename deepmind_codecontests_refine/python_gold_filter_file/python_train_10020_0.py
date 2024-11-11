for _ in range(int(input())):
    n,special=map(int,input().split())
    count=0
    n-=1
    for _ in range(n):
        a,b=map(int,input().split())
        if a==special or b==special:
            count+=1
    if count<=1 or n%2==1:
        print('Ayush')
    else:
        print('Ashish')