n, a, b, c, d = map(int, input().split())
s = input()
print("No" if ("##" in s[a-1:c]) or ("##" in s[b-1:d]) or (c > d and "..." not in s[b-2:d+1]) else "Yes")
