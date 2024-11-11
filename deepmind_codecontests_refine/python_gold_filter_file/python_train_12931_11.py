n,m=list(map(int,input().split()))
s=list(map(str,input().split()))
t=list(map(str,input().split()))
q=int(input())
for _ in range(q):
    z=int(input())
    print(s[z%n-1]+t[z%m-1])