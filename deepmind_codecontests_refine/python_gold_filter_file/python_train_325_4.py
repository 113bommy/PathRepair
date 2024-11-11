n, x, y = map(int, input().split())
numb = list(input())
numb.reverse()
ans = 0
for i in range(x):
    if i==y or i==x:
        if numb[i]=='0':
            ans += 1
    else:
        if numb[i]=='1':
            ans+=1
print(ans)