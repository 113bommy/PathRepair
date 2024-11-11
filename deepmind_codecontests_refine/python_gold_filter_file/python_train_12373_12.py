n = int(input())
lis = [input() for _ in range(n)]

ans = []

for i in "abcdefghijklmnopqrstuvwxyz":
    mn = 50
    for j in lis:
        mn = min(mn,j.count(i))

    ans.append(i*mn)
    
print(''.join(ans))  