#q=int(input())
q=1
for _ in range(q):
    n,w=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    ans1=(n*3)*l[0]
    ans2=((3*n)*(l[n]))/2
    print(min(min(ans1,ans2),w))