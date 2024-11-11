import sys
input = sys.stdin.readline
print = sys.stdout.write
n, m=map(int, input().split())
s=[input() for i in range(n)]
f=[0, 0, ]
acc=0
for i in range(1, m):
    for j in range(n-1):
        if s[j][i]=='X' and s[j+1][i-1]=='X':
            acc+=1
            break
    f.append(acc)
k=int(input())
for i in range(k):
    a, b = map(int, input().split())
    print("YES\n" if f[b]-f[a]==0 else "NO\n")
