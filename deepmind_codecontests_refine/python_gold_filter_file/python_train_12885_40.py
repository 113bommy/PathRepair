S = input()
T = input()
 
res = sum(0 if s == t else 1 for s, t in zip(S,T))
print(res)