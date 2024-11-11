from collections import*
f=lambda:sorted(Counter(input()).values())
print("YNeos"[f()!=f()::2])