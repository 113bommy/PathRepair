for _ in range(int(input())):
    n,m=map(int,input().split())
    diff=abs(n-m)
    total=0
    rem=0
    if(diff%5==0):
        print(diff//5)
    else:
        total+=diff//5
        rem=diff%5
        total+=rem//2
        rem=rem%2
        total+=rem
        print(total)
    
