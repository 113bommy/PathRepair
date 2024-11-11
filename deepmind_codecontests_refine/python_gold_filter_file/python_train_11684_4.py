for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if n==1 :
        if a[0]%2!=0:
            print(-1);continue
        else: print(1);print(1);continue
    for i in range(n):
        if a[i]%2==0:
            print(1);print(i+1);break
        elif a[i]%2!=0 and a[i+1]%2!=0:
            print(2);print(i+1,i+2);break