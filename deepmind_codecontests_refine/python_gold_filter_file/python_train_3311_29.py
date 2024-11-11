r, g, b, n = map(int, input().split())
cnt = 0
for i in range(n+1):
    for j in range(n+1):
        v = r*i + g*j
        if n>=v and (n-v)%b==0: cnt+=1
print(cnt)
