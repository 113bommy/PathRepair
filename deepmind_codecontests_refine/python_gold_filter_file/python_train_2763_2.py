input()
s = input()
h1 = "1" in s or "4" in s or "7" in s
h2 = "3" in s or "6" in s or "9" in s
v1 = "1" in s or "2" in s or "3" in s
v2 = "7" in s or "0" in s or "9" in s
nl = "0" in s
print("YES" if (h1 and h2 and v1 and v2) or (v1 and nl) else "NO")
