n=int(input())
a=list(map(int,input().split()))
m=int(input())
queries=list(map(int, input().split()))
ans = []
for i in range(n):
    ans+=[i]*a[i]
#print(ans)
for q in queries:
    print(ans[q-1]+1)