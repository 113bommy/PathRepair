N, K = map(int, input().split())
s = input()

print(s[:K-1]+s[K-1].lower()+s[K:])
