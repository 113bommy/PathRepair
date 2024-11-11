c0 = input().strip()
cards = [s.strip() for s in input().split()]

def check():
    for c in cards:
        for i in 0, 1:
            if c[i] == c0[i]:
                return True
    return False

ans = "YES" if check() else "NO"
print(ans)
