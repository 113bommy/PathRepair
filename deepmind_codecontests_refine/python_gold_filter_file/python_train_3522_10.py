N = int(input())

ans = [0]*N
for i in range(N-1):
    c,s,f = map(int,input().split())
    ans[i] += s+c
    for j in range(i):
        ans[j] = max((ans[j]+f-1)//f*f, s)+c
for a in ans:
    print(a)