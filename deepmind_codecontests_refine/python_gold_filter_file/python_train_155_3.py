import sys
n, k = map(int, input().split())
a, b, c, d = map(int, input().split())
if(k<n+1 or n==4):
    print(-1)
    sys.exit()
ans = [a, c]
l = [i for i in range(1, n+1) if (i!=a and i!=b and i!=c and i!=d)]
for i in l:
    ans.append(i)
ans.extend([d, b])
for i in ans:
    print(i, end=' ')
print()
ans[0], ans[1] = ans[1], ans[0]
ans[n-2], ans[n-1] = ans[n-1], ans[n-2]
for i in ans:
    print(i, end=' ')
print('\n')