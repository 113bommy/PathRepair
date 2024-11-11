n,m=map(int,input().split())
s=input().split()
t=input().split()
q=int(input())
for i in range(q):
    a=int(input())
    print(s[a%n-1]+t[a%m-1])
