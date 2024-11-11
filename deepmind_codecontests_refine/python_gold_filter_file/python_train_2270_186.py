n,k = map(int,input().split())
s=input()
l=s[k-1].lower()
print(s[:k-1]+l+s[k:])