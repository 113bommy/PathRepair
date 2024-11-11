n,k = map(int,input().split())
s = input()
a = s[:k-1] + s[k-1].lower() + s[k:]
print(a)
