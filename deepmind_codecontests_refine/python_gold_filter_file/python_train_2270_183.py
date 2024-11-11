n, k = map(int, input().split())
s = input()
h = s[k-1].lower()
print(s[:k-1] + h + s[k:])