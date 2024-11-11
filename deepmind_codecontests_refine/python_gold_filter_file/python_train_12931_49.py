n,m=map(int,input().split())
s=input().split()
t=input().split()
q=int(input())
for i in range(q):
    k=int(input())
    print(s[k%n-1]+t[k%m-1])