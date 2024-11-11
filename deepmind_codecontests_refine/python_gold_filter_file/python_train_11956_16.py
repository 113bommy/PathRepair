n=int(input())
k=int(input())
a=list(map(int,input().split()))
ans = 0
for i in a:
    ans+=min(i*2,abs(k-i)*2)
print(ans)
