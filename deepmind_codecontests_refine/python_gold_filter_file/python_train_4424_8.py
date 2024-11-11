a, s, ok = "CODEFORCES", input(), False
for i in range(len(a)+1):
    if s.startswith(a[:i]) and s.endswith(a[i:]):
        ok = True
        break
print("YES" if ok else "NO")

    
