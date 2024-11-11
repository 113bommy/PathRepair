a,b=map(int,input().split())
s=input()
print(s[:b-1]+s[b-1].lower()+s[b:])