def solve():
    a,b,c=map(int,input().split())
    if a==1 and b==1 and c==1:
        print(1)
        return
    print(max(a,b,c)+1)
   


for _ in range(int(input())):
    solve()