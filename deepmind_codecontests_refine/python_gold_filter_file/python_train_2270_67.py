n,m=map(int,input().split())
s=input()
print(s[:m-1]+s[m-1].lower()+s[m:])