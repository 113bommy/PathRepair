from collections import Counter as cnt
fnc = lambda: cnt(cnt(input()).values())
print("Yes" if fnc() == fnc() else "No")