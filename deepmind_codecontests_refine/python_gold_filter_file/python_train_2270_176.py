n,k = map(int,input().split())
s = str(input())
print(s[:k-1]+s[k-1].lower()+s[k:])