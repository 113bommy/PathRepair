n, k = map(int,input().split())
s = input()
print(s[:k-1] + s.lower()[k-1] + s[k:n])
