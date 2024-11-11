n,k=map(int,input().split())
s=input()
ss=s[k-1]

print(s[:(k-1)]+ss.lower()+s[k:])