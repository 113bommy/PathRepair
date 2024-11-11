from sys import stdin
input=stdin.readline
rn=lambda:int(input())
rns=lambda:map(int,input().split())
rl=lambda:list(map(int,input().split()))
rs=lambda:input().strip()
YN=lambda x:print('YES') if x else print('NO')
mod=10**9+7

for _ in range(rn()):
    n=rn()
    a=rl()
    ans=[]
    def solve(b):
        ans=[]
        for i in range(0,len(b),2):
            ans.append(-b[i+1])
            ans.append(b[i])
        return ans
    if n%2==0:
        ans=solve(a)
    else:
        x,b,c=a[:3]
        l=len({x, b, c})
        if l==3:
            pre = [b-c,c-x,x-b]
        elif l==1:
            pre = [1,1,-2]
        else:
            if x==b:
                pre=[x,c-x,-x]
            elif x==c:
                pre=[x,-x,b-x]
            else:
                pre=[-b,b,x-b]
        ans=pre+solve(a[3:])
    print(*ans)