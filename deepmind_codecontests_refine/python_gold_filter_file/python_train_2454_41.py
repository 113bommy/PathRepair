[a] = map(int, input().split())
[b] = map(int, input().split())
[c] = map(int, input().split())

x=min(a,b//2,c//4)

print(int(x*7))