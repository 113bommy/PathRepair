n,m = map(int, input().split())
name = {}
for i in range(n):
    arr = input().split()
    name[arr[1]] = arr[0]
for i in range(m):
    s = input()
    s = s[:-1]
    s = s.split()
    print(" ".join(s), "; #", name[s[1]], sep="")

