from collections import Counter
s=sorted(Counter(input()).values())
t=sorted(Counter(input()).values())
print("Yes" if s==t else "No")